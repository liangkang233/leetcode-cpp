/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
// 动态规划 在 分治的思路之上 考虑填充气球
// 令 dp[i][j] 表示填满开区间 (i,j) 能得到的最多硬币数， 那么边界条件是 i≥j−1， 此时有 dp[i][j]=0。
// 设 dp[i][j] 为填充区间 i到j 的最大值  (左右区间不戳破的值) 
// 转移方程 dp[i][j] = dp[i][k] + dp[k][j] + val[i] * val[k] * val[j]
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size()+2, 0));
        vector<int> v(2, 1);
        v.insert(v.begin()+1, nums.begin(), nums.end());
        for (int i = nums.size()-1; i >=0; i--) {
            for (int j = i+2; j <= nums.size()+1; j++) {
                // cout << i << " and " << j << endl;
                for (int k = i+1; k < j; k++) {
                    // cout << dp[i][k] << " " << dp[k][j] << " : " << k << endl;
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + v[i]*v[k]*v[j]);
                }
            }
        }
        return dp[0][nums.size()+1];
    }
};
// @lc code=end


// 记忆化 分治法   反过来思考 假设当前戳破的是最后一个球 (添加的思想)
// 则数值为 左区间值 + 右区间值 + 最后戳破的i 与此时左右边界相乘值
// 而左右区间的值 递归下去计算
class Solution {
public:
    int mydfs(vector<vector<int>>& s, vector<int>& v, int l, int r) {
        if(l >= r-1)  return 0;
        if(s[l][r] != -1) return s[l][r]; // 去重记录
        for (int i = l+1; i < r; i++) {
            int temp = v[l] * v[i] * v[r];
            temp += mydfs(s, v, l, i) + mydfs(s, v, i, r);
            s[l][r] = max(s[l][r], temp);
        }
        return s[l][r];
    }
    int maxCoins(vector<int>& nums) {
        vector<vector<int>> s(nums.size()+2, vector<int>(nums.size()+2, -1));
        vector<int> v(2, 1);
        v.insert(v.begin()+1, nums.begin(), nums.end());
        return mydfs(s, v, 0, nums.size()+1);
    }
};
