/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = 0;
        for (int i = 0; i < nums.size(); i++)
            s += nums[i];
        if(s % 2 == 1)
            return false;
        s /= 2;
        vector<int> dp(s+1, false);
        dp[0] = true;
        // dp[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数（可以是 0 个），是否存在一种选取方案使得被选取的正整数的和等于 j
        for (int i = 1; i < nums.size(); i++) {
            for (int j = s; j>=0; j--) { // 注意与 494题一样需要逆序
                if(j-nums[i-1] >= 0 && dp[j-nums[i-1]])
                    dp[j] = true;
            }
            if(dp[s])
                return true;
        }
        return false;
    }
};
// @lc code=end

/* 进阶 计算分割方法数 s为数组元素和的一半
vector<int> dp(s+1, 0);
dp[0] = 1;
for (int i = 1; i <= nums.size(); i++) {
    for (int j = s; j >= 0; i++) {
        if(j >= nums[i])
            dp[j] += dp[j-nums[i]];
    }
}
return dp.back(); */

// 记忆化dfs
class Solution {
    // unordered_map<int, int> mp; 求个数用map 判断是否存在只要 set即可
    unordered_set<int> mp;
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if(sum & 1) return false;
        return helper(nums, sum / 2, 0);
    }
    bool helper(vector<int>& nums, int target, int i){
        int key = i + 1000 * target;
        if(target == 0) return true;
        if(target < 0 || i >= nums.size()) return false;
        if(mp.find(key) != mp.end())
            return false;
        bool res = helper(nums, target - nums[i], i + 1) || helper(nums, target, i + 1);
        mp.insert(key);
        return res;
    }
};
