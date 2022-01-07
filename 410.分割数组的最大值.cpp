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
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return (int)f[n][m];
    }
};