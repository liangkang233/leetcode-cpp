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