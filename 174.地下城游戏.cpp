/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size(), N = dungeon[0].size();
        vector<vector<int>>dp(M, vector<int>(N, 0));
        // dp[M-1][N-1] = dungeon[M-1][N-1] < 0 ? -dungeon[M-1][N-1] + 1 : 1; // 等价下面的
        dp[M-1][N-1] = max(1-dungeon[M-1][N-1], 1);
        for (int i = M-1; i >= 0; i--) {
            for (int j = N-1; j >= 0; j--) {
                int right = INT_MAX, down = INT_MAX;
                if(i == M-1 && j == N-1)
                    continue;
                if(i < M-1)
                    right = dp[i+1][j];
                if(j < N-1)
                    down = dp[i][j+1];
                // dp[i][j] = dungeon[i][j]-min(right, down) < 0 ? -dungeon[i][j]+min(right, down) : 1; // 等价下面的 <0就是<=-1
                dp[i][j] = max(min(right, down)-dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

// 大有问题
typedef pair<int, int> mypair;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // 动态规划，维护pair数组 路径确保所得值最大 first为路径中生命值的最小值 second为当前生命值(累加和)
        int M = dungeon.size(), N = dungeon[0].size();
        vector<vector<mypair>> ans(M, vector<mypair>(N, mypair(0,0)));
        ans[0][0] = make_pair(dungeon[0][0], dungeon[0][0]);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (i == 0 && j == 0)
                    continue;
                int up = INT_MIN, left = INT_MIN;
                if (i > 0)
                    left = ans[i-1][j].second; 
                if (j > 0)
                    up = ans[i][j-1].second;
                // 挑选累加和更大的路 并记录路中生命值最小值
                if(left > up) {
                    ans[i][j].second = dungeon[i][j] + left, ans[i][j].first = ans[i-1][j].first;
                }
                else{
                    ans[i][j].second = dungeon[i][j] + up, ans[i][j].first = ans[i][j-1].first;
                }
                if (ans[i][j].second < ans[i][j].first)
                    ans[i][j].first = ans[i][j].second;
            }
        }
        return ans[M - 1][N - 1].first < 0 ? abs(ans[M - 1][N - 1].first) + 1 : 1;  //生命值必为正整数
    }
};