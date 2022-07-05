/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp (n+1, 0); // dp[i] 代表 长度为i的二叉搜索树种类
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) { // 以第j个节点为根节点
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp.back();
    }
};
// @lc code=end

// 卡塔兰数
// c[0] = 1, C[n+1] = 2*(2*n+1) / (n+2) * C[n];
// 证明 https://baike.baidu.com/item/catalan/7605685?fr=aladdin
class Solution {
public:
    int numTrees(int n) {
        long long C = 1;
        for (int i = 0; i < n; ++i) {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};