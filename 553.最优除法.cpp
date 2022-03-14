/*
 * @lc app=leetcode.cn id=553 lang=cpp
 *
 * [553] 最优除法
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 此处规定 元素在区间 [2, 1000]
    // 即想让 a / b 尽量大 只需要 b尽量小即可。 即 b 先除后面所有的数
    string optimalDivision(vector<int>& nums) {
        string ans;
        if (nums.size() == 1)
            ans = to_string(nums[0]);
        else if (nums.size() == 2)
            ans = to_string(nums[0]) + "/" + to_string(nums[1]);
        else {
            ans = to_string(nums[0]) + "/(" + to_string(nums[1]);
            for (int i = 2; i < nums.size(); i++)
                ans += "/" + to_string(nums[i]);
            ans += ")";
        }    
        return ans;
    }
};
// @lc code=end
// [2, 3]\n
// [200, 3, 7]\n

// 动态规划 通用方法可用于非特定情况
struct Node {
    double maxVal, minVal;
    string minStr, maxStr;
    Node() {
        this->minVal = 10000.0;
        this->maxVal = 0.0;
    }
};

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        vector<vector<Node>> dp(n, vector<Node>(n));

        for (int i = 0; i < n; i++) {
            dp[i][i].minVal = nums[i];
            dp[i][i].maxVal = nums[i];
            dp[i][i].minStr = to_string(nums[i]);
            dp[i][i].maxStr = to_string(nums[i]);
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j + i < n; j++) {
                for (int k = j; k < j + i; k++) {
                    if (dp[j][j + i].maxVal < dp[j][k].maxVal / dp[k + 1][j + i].minVal) {
                        dp[j][j + i].maxVal = dp[j][k].maxVal / dp[k + 1][j + i].minVal;
                        if (k + 1 == j + i) {
                            dp[j][j + i].maxStr = dp[j][k].maxStr + "/" + dp[k + 1][j + i].minStr;
                        } else {
                            dp[j][j + i].maxStr = dp[j][k].maxStr + "/(" + dp[k + 1][j + i].minStr + ")";
                        }
                    }
                    if (dp[j][j + i].minVal > dp[j][k].minVal / dp[k + 1][j + i].maxVal) {
                        dp[j][j + i].minVal = dp[j][k].minVal / dp[k + 1][j + i].maxVal;
                        if (k + 1 == j + i) {
                            dp[j][j + i].minStr = dp[j][k].minStr + "/" + dp[k + 1][j + i].maxStr; 
                        } else {
                            dp[j][j + i].minStr = dp[j][k].minStr + "/(" + dp[k + 1][j + i].maxStr + ")"; 
                        }
                    }
                }
            }
        }
        return dp[0][n - 1].maxStr;
    }
};
// 链接：https://leetcode-cn.com/problems/optimal-division/solution/zui-you-chu-fa-by-leetcode-solution-lf4c/