/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
// 动态规划 记数组的元素和为 sum，添加 - 号的元素之和为 neg
// 则其余添加 + 的元素之和为 sum−neg，得到的表达式的结果为 sum-2*neg = target
// neg 为 非负整数 所以 sum-target 必为非负偶数 否则无解
// dp[i][j] 表示在数组 nums 的前 i 个数中选取元素，使得这些元素之和等于 j
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, T;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        T = sum - target;
        if(T < 0 || (T&1) == 1) return 0;
        T/=2; // neg 即求nums中元素相加和为 T(neg) 的个数
        vector<vector<int>> dp(nums.size()+1, vector<int>(T+1, 0)); // dp[i][j] 表示 i个元素合为j的个数
        dp[0][0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= T; j++) { // 和大于T后没必要计入
                if(j >= nums[i-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]]; // 加上当前元素 或不加
                else
                    dp[i][j] = dp[i-1][j]; // 会超出j 只能不加
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        return dp.back().back();
    }
};
// @lc code=end
// [1,2,3,4,5,6,67,3,47,54,6,5,8,76,9,0,8,90,95,9]\n12
// [0,0,0,0,0,0,0,0,1]\n1

// 压缩为1维 倒序遍历 可以少用一个数组 swap 的优化版本
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, T;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        T = sum - target;
        if(T < 0 || (T&1) == 1) return 0;
        T/=2; // neg 即求nums中元素相加和为 T(neg) 的个数
        vector<int> dp(T+1, 0); // dp[i][j] 表示 i个元素合为j的个数 压缩后 只需要 j 不需要i
        dp[0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = T; j >= nums[i-1]; j--) {
                dp[j] += dp[j-nums[j-1]];
                // 没有遍历 的元素相当于不加上该元素 dp[i][j] = dp[i-1][j]
                // 有遍历 的元素相当于 加和 不加上该元素 dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
            }
        }
        return dp.back();
    }
};

// 直接暴力 记录
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        mymap[nums[0]] += 1;
        mymap[-nums[0]] += 1; // 使用 = 1 第一个元素为0 时会少记录一半
        for (int i = 1; i < nums.size(); i++) {
            unordered_map<int, int> temp;
            for (const pair<int, int>& ij : mymap) {
                temp[ij.first + nums[i]] += ij.second;
                temp[ij.first - nums[i]] += ij.second;
            }
            swap(mymap, temp);
            // for (auto &&i : mymap) {
            //     cout << i.first << ":" << i.second << " ";
            // } cout << endl; 
        }
        return mymap[target];
    }
};

// 二刷
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        // 假设符号为负号的和为K 则 sum-k + -k == target
        int K = sum - target;
        if(K < 0 || K % 2 == 1)
            return 0;
        K /= 2;
        // vector<vector<int>> dp(nums.size()+1, vector<int>(K+1, 0)); // dp[i][j] 长度为i 大小为j 的组合个数
        vector<int> dp(K+1, 0); // 压缩为1维
        dp[0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = K; j >= 0; j--) { // 倒序遍历 还可以少一个数组 swap
                if(j >= nums[i-1])
                    dp[j] += dp[j-nums[i-1]];
            }
        }
        return dp[K];
    }
};