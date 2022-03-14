/*
 * @lc app=leetcode.cn id=2055 lang=cpp
 *
 * [2055] 蜡烛之间的盘子
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int temp = 0, index = 0;
        vector<int>ans(queries.size(), 0);
        vector<pair<int, int>> record; //record 记录 盘子前缀和 的有效下标
        while (index < s.size() && s[index] == '*') index++;
        for (; index < s.size(); index++) {
            if(s[index] == '|')
                record.push_back(make_pair(index, temp));
            else
                temp++;
        }
        // 使用lower_bound改造二分法找盘子前缀下标 右边界处理方式不同 不是直接取第1个大于等于num下标
        auto mylower_bound = [&record](int num, bool flag) -> int {
            int i = 0, j = record.size() - 1;
            // if(record[j].first <= num)   return record[j].second; 不影响结果
            while (i < j) {
                int mid = (i + j) >> 1;
                if(record[mid].first < num)
                    i = mid + 1;
                else
                    j = mid;
            }
            if(flag && i>0 && record[i].first > num)
                i--;
            return record[i].second;
        };

        if(!record.empty()) {
            for (int i = 0; i < queries.size(); i++) {
                int end = queries[i][1], start = queries[i][0];
                ans[i] = max(mylower_bound(end, true) - mylower_bound(start, false), 0); //有可能左右区间在同一段 结果负数
            }
        }
        return ans;
    }
};
// @lc code=end

// ""***|**|*****|**||**|*"\n[[1,17],[4,5],[14,17],[5,11],[15,16]]\n"
// ""***|*****************"\n[[1,17],[4,5],[14,17],[5,11],[15,16]]\n"
// ""***|****|||||||****|****|**|***"\n[[1,17],[4,5],[14,17],[5,11],[15,16]]\n"
// ""***|**|*****|**||**|*"\n[[0,2]]\n"


// 绝了 大佬的方法 fs[i]代表i右边第一个蜡烛后面的盘子 最开始也是这么想的 但是最后做错了 直接 fs[end] - fs[start] 了，没有rear的坐标映射
class Solution {
public:
    // 预处理查询问题，处理出每个位置右侧有多少个盘子以及每个位置的下一个蜡烛的坐标，随后O(1)每次查询
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int c = 0, w = 0, n = s.size(), m = queries.size();
        vector<int> fs(n), rear(n), ans(m);
        for(int i = n - 1; i >= 0; --i){ //左边界
            s[i] == '*' ? ++c : w = c;
            fs[i] = w;
        }
        for(int i = 0, j = 0; i < n; ++i){  //右边界
            if(s[i] != '*') j = i;
            rear[i] = j;
        }
        for(int i = 0; i < m; ++i){
            ans[i] = max(0, fs[queries[i][0]] - fs[rear[queries[i][1]]]);
        }
        return ans;
    }
};