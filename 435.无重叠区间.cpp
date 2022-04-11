/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 贪心 先按照区间首元素排序后 遍历有重合时删除 尾部更长的 降低后续的区间重复的可能
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0, tail = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < tail) { // 有重合 tail 取较小值 即舍去尾部扩展更长的区间
                ans++;
                tail = min(tail, intervals[i][1]);
            }
            else
                tail = intervals[i][1];
        }
        return ans;
    }
};
// @lc code=end
// [[1,2],[1,2],[1,2],[1,3],[1,2],[3,4],[3,5],[2,3]]
// [[1,2],[2,3],[2,4],[4,5],[3,4],[5,8],[3,5],[3,8],[3,6],[5,7],[2,4],[5,10]]
// [[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]]