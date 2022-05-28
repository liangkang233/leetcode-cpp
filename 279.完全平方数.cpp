/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
// 动态规划
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 1000);
        int N = 1;
        for (int j = 1; j <= n; j++) {
            if(j == N*N) {
                N++;
                dp[j] = 1;
            } else {
                // 这么写会超时
                // for (int i = j-1; i >= j/2; i--) 
                //     dp[j] = min(dp[i] + dp[j-i], dp[j]);
                // 优化为 平方数相加
                for(int i = 1; i * i <= j; i++) {
                    dp[j] = min(dp[j-i*i]+1, dp[j]);
                }
            }
        }
        return dp.back();
    }
};
// @lc code=end
// 6337

// bfs
class Solution {
public:
    int numSquares(int n) {
        queue<pair<int, int>> myque;
        myque.push(make_pair(0, 0));
        while (!myque.empty()) {
            pair<int, int> A = myque.front();
            myque.pop();
            for (int i = 1; i*i + A.first <= n; i++) {
                // cout << i*i + A.first << " " << A.second+1 << endl;
                if(i*i + A.first == n)
                    return A.second+1;
                myque.push(make_pair(i*i + A.first, A.second+1));
            }
        }
        return -1;
    }
};