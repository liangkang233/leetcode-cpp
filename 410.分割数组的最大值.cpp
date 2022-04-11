/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 注意 题中是要非空连续子数组 一开始想复杂了
// [使……最大值尽可能小] 是二分搜索题目常见的问法。

// @lc code=start
class Solution {
public:
    // 二分法 绝
    bool isok(vector<int>& nums, int mid, int m) {
        int count = 1, temp = 0;
        for(auto num : nums) {
            if ( temp + num <= mid) 
                temp += num;
            else {
                temp = num;
                count ++;
            }
        }
        return count > m;
    }
    int splitArray(vector<int>& nums, int m) {
        int L = -1,R = 0, mid;
        // L为整个数组的最大值 R为整个数组的总和 分割的子数组和的最大值 取值范围即在L R之中
        // 由于分割次数 m 和 分割子数组和的最大值 成线性负相关 关系 所以可以采用二分的方法 靠近测试
        for (auto num : nums) {
            L = max(L, num);
            R += num;
        }
        while(L < R) {
            mid = (L + R)/2;
            if(isok(nums, mid, m))
                L = mid+1;
            else 
                R = mid;
        }
        return L;   // L==R
    }
};
// @lc code=end

class Solution {
public:
    // 动态规划 不推荐
    int splitArray(vector<int>& nums, int m) {
        // 构建一个dp数组 dp[i][j]代表i个长度的数组分为j段的数组和大值的最小值
        int n = nums.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            // 这里优化了时间 不必要遍历计算 j 大于 i 的结果 (之前的计算一定包含了正确答案)
            for (int j = 1; j <= min(i, m); j++) {
                // 同理 k 在0 到 i-1的范围内遍历 时不必要 取到长度 k 比分割次数 j-1 小的情况 (这些值的答案都包含在dp[j-1][j-1]中)
                for (int k = j-1; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        // for (auto &&o : f) {
        //     for (auto &&oo : o)
        //         cout << oo << " ";
        //     cout << endl;
        // }    
        return (int)f[n][m];
    }
};


class Solution {
public:
    // 动态规划 不推荐
    int splitArray(vector<int>& nums, int m) {
        // 构建一个dp数组 dp[i][j]代表i个长度的数组分为j段的数组和大值的最小值
        int n = nums.size();
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
        vector<long long> sub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            // 这里优化了时间 不必要遍历计算 j 大于 i 的结果 (之前的计算一定包含了正确答案)
            for (int j = 1; j <= min(i, m); j++) {
                // 同理 k 在0 到 i-1的范围内遍历 时不必要 取到长度 k 比分割次数 j-1 小的情况 (这些值的答案都包含在dp[j-1][j-1]中)
                for (int k = j-1; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        // for (auto &&o : f) {
        //     for (auto &&oo : o)
        //         cout << oo << " ";
        //     cout << endl;
        // }    
        return (int)f[n][m];
    }
};


// 二刷 动态规划
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long ans = LLONG_MAX;
        // int 会溢出
        vector<vector<long long>> dp(nums.size(), vector<long long>(m, LLONG_MAX));
        vector<long long> prefix(nums.size(), nums[0]); // 前缀和辅助数组
        for (int i = 1; i < nums.size(); i++) { // 初始化
            prefix[i] = prefix[i-1] + nums[i];
            dp[i][0] = prefix[i];
        }
        for (int i = 0; i < m; i++)
            dp[0][i] = prefix[0];

        for (int i = 1; i < nums.size(); i++) { // dp[i][j] 表示切分j+1次 i+1为数组长度
            for (int j = 1; j <= min(i, m-1); j++) { // 注意切分次数 j+1 最大为m 或者 当前长度i+1
                for (int ii = 0; ii < i; ii++)
                    dp[i][j] = min(dp[i][j], max(dp[ii][j-1], prefix[i] - prefix[ii]));
            }
        }
        return (int)dp.back().back();
    }
};
// @lc code=end
// [1,3,67,834,7,4,63,6,83,8,3,895,8,436,6]\n3