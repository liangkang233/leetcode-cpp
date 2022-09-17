/*
 * @lc app=leetcode.cn id=857 lang=cpp
 *
 * [857] 雇佣 K 名工人的最低成本
 */

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 求职内卷题了 贪心用能力高 工资低的人 只要满足 工资/能力 max的人做计算
// 然后根据区间内 k个quality 来计算 需要成本 遍历一遍
// https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/solution/gu-yong-k-ming-gong-ren-de-zui-di-cheng-rsz3t/

// @lc code=start
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double ans = DBL_MAX, now = 0.0;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i].first = quality[i]; 
            v[i].second = wage[i];
        }
        auto mycmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            // return (double)a.second / (double)a.first < (double)b.second / (double)b.first; // 做除法 要强转 double  用乘法更好
            return a.second * b.first < b.second * a.first;
        };
        sort(v.begin(), v.end(), mycmp);
        
        priority_queue<int, vector<int>, less<int>> q; // 构造一个辅助堆 每次添加 工资/能力 max的人 删除之前记录的区间内 quality最大的人
        int all_q = 0;
        for(int i = 0; i < k-1; i++) {
            q.push(v[i].first);
            all_q += v[i].first;
        }
        for (int i = k-1; i < n; i++) {
            q.push(v[i].first);
            all_q += v[i].first;
            now = (double)all_q * v[i].second / v[i].first; // 关键计算公式 由max 工资/能力 推导出的最低成本
            ans = min(now, ans);
            all_q -= q.top();
            q.pop();
        }
        return ans;
    }
};
// @lc code=end

// [4,4,4,5]\n[13,12,13,12]\n2