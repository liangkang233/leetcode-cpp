/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool flag = true;
        vector<vector<int>> ans;
        int L = newInterval[0], R = newInterval[1];
        for (int i = 0; i < intervals.size(); i++) {
            if(intervals[i][0] > R) {
                if (flag) {
                    flag = false;
                    ans.push_back(vector<int>{L, R});
                }
                ans.push_back(vector<int>{intervals[i][0], intervals[i][1]});
            }
            else if(intervals[i][1] < L) {
                ans.push_back(vector<int>{intervals[i][0], intervals[i][1]});
            }
            else {
                L = min(L, intervals[i][0]);
                R = max(R, intervals[i][1]);
            }
        }
        if(flag)
            ans.push_back(vector<int>{L, R});
        return ans;
    }
};
// @lc code=end

/***   二分后合并区间太多需要考虑的，弃用    ***/

// vector 删元素很慢 二分找后 再删除这样会超时
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int L = newInterval[0], R = newInterval[1];
        auto it = upper_bound(intervals.begin(), intervals.end(), vector<int>{L}, 
            [](const vector<int>& i, const vector<int>& j) {return i[0] < j[0];});
        if(it != intervals.begin()) { // 按照左区间二分查 寻找在intervals左界限 递增序列中 找到第一个 大于 newInterval的左边界 的迭代器
            auto it1 = it - 1;
            if( (*it1)[1] >= R) { // 由于使用 upper， it1 的左边界一定小于等于 L
                return intervals;
            } else if ((*it1)[1] >= L ) { // 改变左区间值
                L = (*it1)[1];
                it = intervals.erase(it1); // 注意这里删了it1 it会失效 要重新获取
            }
        }
        while (it != intervals.end() &&  R >= (*it)[0]) { // 删除被R覆盖的区间
            R = max(R, (*it)[1]);
            it = intervals.erase(it); // earse 后 返回的是删除元素后一个的迭代器
        }
        intervals.insert(it, vector<int>{L, R});
        return intervals;
    }
};

// 较为简洁的方案 二分找索引只要找 右边界第一个大于等于 L 的 省去不少判断
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        // 步骤一：找到需要合并的区间
        // 即 在intervals右界限 递增序列中 找到第一个 大于等于 newInterval的左边界 的迭代器
        // while (index < intervals.size() && intervals[index][1] < newInterval[0])
        //     result.push_back(intervals[index++]);
        auto it = lower_bound(intervals.begin(), intervals.end(), vector<int>{0, newInterval[0]},
            [](const vector<int>& i, const vector<int>& j) {return i[1] < j[1];}); 
        result.insert(result.begin(), intervals.begin(), it); // 复制intervals 的 begin 到 it-1 区间值
        
        // 步骤二：合并区间
        while (it != intervals.end() && (*it)[0] <= newInterval[1]) {
            newInterval[0] = min( (*it)[0], newInterval[0]);
            newInterval[1] = max( (*it)[1], newInterval[1]);
            it++;
        }
        result.push_back(newInterval);

        // 步骤三：处理合并区间之后的区间
        result.insert(result.end(), it, intervals.end());
        return result;
    }
};