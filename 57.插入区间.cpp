/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

#include <iostream>
#include <vector>
#include <map>
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
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int L,R;
    int start = 0, end = intervals.size() - 1;
    while (start <= end) { // 先二分 找到插入位置
        int mid = (start + end) / 2;
        if(intervals[mid][0] > newInterval[0])
            start = mid + 1;
        else
            end = mid - 1;
    }// start 范围为 0-size
    L = start; // R大于0小于size时 intervals[L] <= newInterval[L] < intervals[L+1]
    end = intervals.size() - 1;
    while (start <= end) { // 再次二分 计算尾部插入位置
        int mid = (start + end) / 2;
        if(intervals[mid][1] > newInterval[1])
            start = mid + 1;
        else
            end = mid - 1;
    }// start 范围为 L-size
    R = start; // R大于0小于size时 newInterval[R] <= newInterval[R] < newInterval[R+1]

    vector<int> temp(newInterval); // 合并后区间
    for (int i = 0; i <= L-1; i++) // 把之前的片段先复制过来
        ans.push_back(intervals[i]);
    if(L > 0) {
        if(L < intervals.size() && newInterval[0] <= intervals[L][1])
            temp[0] = intervals[L][0];
        else
            ans.push_back(intervals[L]);
    }
    else {

    }

    if(R < intervals.size()) {
        if(newInterval[0] >= intervals[R][0])
            temp[1] = intervals[L-1][0];
        else 
            R++;
    }
    ans.push_back(temp);
    for (int i = R+1; i < intervals.size(); i++) // 把之后的片段复制过来
        ans.push_back(intervals[i]);
    return ans;
}
