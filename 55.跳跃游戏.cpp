/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// @lc code=start
// 从头到尾的贪心遍历 比尾部反向遍历要快
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxn = nums[0];
        for (int i = 0; i <= maxn; i++) {
            maxn = max(maxn, nums[i] + i);
            if (maxn >= nums.size() - 1)
                return true;
        }
        return false;
    }
};
// @lc code=end

// 贪心 从尾部遍历到头 记录能够到达头部的最小下标 只要当前位置到达最小下标的距离小于等于跳跃值即可判定该节点为true
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int R = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0 ; i--) {
            if(nums[i] >= R - i)
                R = i;
        }
        return nums[0] >= R - 0;
    }
};
// [0]
// [2,3,1,1,4,6,7,3,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,6]\n
// [3,2,1,0,4]\n


// bfs 会超时很慢
bool canJump(vector<int>& nums) {
    queue<int> que;
    cout << que.size() << endl;
    // vector<bool> ans(nums.size(), false);
    // ans[0] = true;
    while (!que.empty()) {
        int id = que.front();
        que.pop();
        for (int len = nums[id]; len > 0; len--) {
            if(len + id >= nums.size() - 1 )
                return true;
            que.push(len + id);
        }
    }
    return false;
}

// 动态规划 也很慢很蠢 （未写完）
bool canJump(vector<int>& nums) {
    vector<vector<bool>> dp(nums.size(), vector<bool>(nums.size(), true));
    // dp[0][0] = true; // dp[i][j]表示从下标i到下标j是否可行
    for (int j = 0; j < nums.size(); j++) {
        for (int i = j-1; i >= 0; i--) {
            if (nums[i]) {
            }
        }
    }
    return dp[0][nums.size()-1];

}