/*
 * meituan-013. 偏爱字母
 *
 * https://leetcode-cn.com/problems/pedXtA/
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 53题目，最大子序和

// 动态规划 时间 空间O(1)
int main1 () 
{   
    // dp[i] 为 以i结尾的子串最大差值
    int n, ans = 0, temp; // ans 0 代表 空串 动态规划没法表示空串
    string s;
    cin >> n >> s;
    int dp = s[0]=='E' ? 1 : -1;
    for (int i = 1; i < n; i++) {
        int temp = s[i]=='E' ? 1 : -1;
        dp = max(dp + temp, temp); // 动态方程为 i-1区间最大值包含i尾部， 删除i-1区间
        // dp[i] = max(dp[i-1] + temp, temp); // 动态方程为 i-1区间最大值包含i尾部， 删除i-1区间
        ans = max(ans, dp);
    }
    cout << ans << endl;
    return 0;
}

// 一次遍历 记录区间值 时间O(n) 空间O(1)
int main () 
{
    int n, ans = 0, temp = 0; // temp 为当前遍历值
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if(s[i] == 'E') {
            temp++;
            ans = max(temp, ans);
        }
        else {
            temp--;
            temp = max(0, temp);
        }
    }
    cout << ans << endl;
    return 0;
}

    // vector<vector<int>> dp(n, vector<int>(n, 0)); //dp[i][j] 代表字符串 下标从 i到j 的E长度减去比F长度
    // for (int i = 0; i < n; i++) {
    //     dp[i][i] = s[i]=='E' ? 1 : -1;
    //     for (int j = i+1; j < n; j++) {
    //         dp[i][j] = dp[i][j-1] + (s[j]=='E' ? 1 : -1);
    //         ans = max(dp[i][j], ans);
    //     }
    // }
    // 暴力 时间O(n^2) 不可 这里空间也超了 应该写成维护一个数