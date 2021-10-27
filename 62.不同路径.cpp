/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <vector<int>> array(m, vector<int>(n, 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0)
                    continue;
                array[i][j] = array[i-1][j] + array[i][j-1];
            }
        }
        return array[m-1][n-1];
    }
};
// @lc code=end

// 排列组合做法
/* 从左上角到右下角的过程中，我们需要移动 m+n−2 次，
其中有 m-1 次向下移动，n-1 次向右移动。
因此路径的总数，就等于从 m+n-2 次移动中选择 m−1 次向下移动的方案数，即组合数： */
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};

