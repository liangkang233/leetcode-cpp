/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [56] 合并区间
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto myfunc = [](vector<int> a, vector<int> b) -> bool {
            return a[0] < b[0]; };
        sort(intervals.begin(), intervals.end(), myfunc);
        int num = intervals.size(), L = intervals[0][0], R = intervals[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i < num; i++) {
            if (intervals[i][1] <= R)
                continue;
            if (intervals[i][0] > R) {
                ans.push_back({L, R});
                L = intervals[i][0];
            }
                R = intervals[i][1];
        }
        ans.push_back({L, R});
        return ans;
    }
};
// @lc code=end

    // 官方法，思路是一样的 不过时间空间都省了
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end()); //二维容器排序默认是将首元素进行对比
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }