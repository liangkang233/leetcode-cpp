/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

#include <iostream>
#include <string>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int mybfs(vector<vector<bool>>& dp) {
        queue<pair<int, int>> myque; // pair first 对应下标 second 为当前行走次数
        unordered_set<int> myset;  // 需要去重 之前就到达过的下标 说明这次到达花费步数肯定更大
        myque.push(make_pair(0, 0));
        while (!myque.empty()) {
            pair<int, int> pi = myque.front();
            myque.pop();
            if(pi.first == dp.size())
                return pi.second;
            for (int i = dp.size()-1; i >= pi.first; i--) { // 一般来说 从后往前遍历好些
                if(dp[pi.first][i] && myset.find(i)==myset.end()) {
                    myset.insert(i);
                    myque.push(make_pair(i+1, pi.second+1));
                }
            }
        }
        return -1;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true)); // dp[i][j] 表示从i到j是否为回文
        for (int j = 1; j < n; j++) {
            for (int i = j-1; i >= 0; i--) {
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
            }
        }
        // for (int i = 0; i < n; i++) { // 这里打印会超时
        //     for (int j = 0; j < n; j++)
        //         cout << dp[i][j] << " ";
        //     cout << "\n";
        // }
        return mybfs(dp)-1;
    }
};
// @lc code=end
// "aaabaa"\n
// "aaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccc"\n
// "aaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeeeaannnbbcccccccccccccccccccaaaaaaaaaaaaaaaayyyyyyyeee"\n



/* 贪心dfs结果不一定 最小 
// dfs 按照从后到前遍历 第一个return 的必定是分割数最少的值 这么思考是错的 例如 "aaabaa"
int mydfs(vector<vector<bool>>& dp, int now, int count) {
    if(now == dp.size())
        return count;
    for (int i = dp.size(); i >= now; i--) {
        if(dp[now][i]) {
            int temp = mydfs(dp, i+1, count+1);
            if(temp > 0)
                return temp;
        }
    }
    return -1;
}

// 如此bfs 很容易超时
int mybfs(vector<vector<bool>>& dp) {
    queue<pair<int, int>> myque; // pair first 对应下标 second 为当前行走次数
    myque.push(make_pair(0, 0));
    while (!myque.empty()) {
        pair<int, int> pi = myque.front();
        myque.pop();
        cout << pi.first << endl;
        if(pi.first == dp.size())
            return pi.second;
        for (int i = dp.size()-1; i >= pi.first; i--) { // 一般来说 从后往前遍历好些
            if(dp[pi.first][i])
                myque.push(make_pair(i+1, pi.second+1));
        }
    }
    return -1;
} */

// 官方再次采用动态规划求
class Solution {
public:
    int myfun(vector<vector<bool>>& dp) {
        vector<int> f(dp.size(), INT_MAX);
        f[0] = 0;
        for (int j = 0; j < dp.size(); j++) {
            if(dp[0][j])
                f[j] = 0;
            for (int i = j; i > 0; i--) {
                if(dp[i][j])
                    f[j] = min(f[j], f[i-1]+1);
            }
        }
        return f.back();
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true)); // dp[i][j] 表示从i到j是否为回文
        for (int j = 1; j < n; j++) {
            for (int i = j-1; i >= 0; i--) {
                dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
            }
        }
        return myfun(dp);
    }
};