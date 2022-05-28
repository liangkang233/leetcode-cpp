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

// 二刷 稍微省点空间
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1); // 记录每一行格子 dp[i] i列的路径数量
        for (int i = 1; i < m; i++) {
            vector<int> temp(n, 1);
            for (int j = 1; j < n; j++) {
                temp[j] = dp[j] + temp[j-1];
            }
            swap(temp, dp);
        }
        return dp[n-1];
    }
};
// 30\n8\n



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

// 二刷
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) { // 即为求 古典概率Cn m+n 一定要正序的做累乘
        m--, n--;
        if(m<n)
            swap(m,n); // 古典概率 交换行列不影响结果 取较小值
        long long ans = 1;
        for (int i = m+1, j = 1; j <= n; i++, j++)
            ans = ans * i / j;
        // 这么做有可能除法会有浮点数 造成错误
        // int N = m+n, ans = 1;
        // for (; m > 0; m--, N--)
        //     ans = ans * N / m; 
        return ans;
    }
};
// @lc code=end