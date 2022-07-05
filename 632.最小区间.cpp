/*
 * @lc app=leetcode.cn id=632 lang=cpp
 *
 * [632] 最小区间
 */

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 该问题可以转化为，从 k 个列表中各取一个数，使得这 k 个数中的最大值与最小值的差最小。
// 可以维护一个小根堆 计算当前k个值的 最大值 最小值之差
// 填入 下标为0 的k个元素 不断计算 差值 确定ans上下限 查出范围时 对应节点 pop 并 push该节点的下一个值


// 使用最小堆维护 k 个指针指向的元素中的最小值，同时维护堆中元素的最大值。
// 初始时，k 个指针都指向下标 0，最大元素即为所有列表的下标 0 位置的元素中的最大值。
// 每次从堆中取出最小值，根据最大值和最小值计算当前区间，如果当前区间小于最小区间则
// 用当前区间更新最小区间，然后将对应列表的指针右移，将新元素加入堆中，
// 并更新堆中元素的最大值。

// @lc code=start
struct mycmp {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> que; // 小根堆
        int MINI, L = -1e5, MAXI = INT_MIN, R = 1e5;
        for (int i = 0; i < nums.size(); i++) { // 下标为[i][j] first 为 i*100+j, second为 nums[i][j]
            que.push(make_pair(i*100 + 0, nums[i][0]));
            MAXI = max(MAXI, nums[i][0]);
        }
        while (!que.empty()) {
            auto pi = que.top();
            que.pop();
            int i = pi.first / 100, j = pi.first % 100;
            MINI = pi.second;
            if(MAXI - MINI < R -L) {
                R = MAXI;
                L = MINI;
            }
            if(j == nums[i].size() - 1) break; // 该类到达最尾部 无法再删减 且题中要包含所有元素 所以可以退出循环了
            j++;
            MAXI = max(MAXI, nums[i][j]);
            que.push(make_pair(i*100 + j, nums[i][j]));
        }
        return vector<int> {L, R};
    }
};
// @lc code=end

