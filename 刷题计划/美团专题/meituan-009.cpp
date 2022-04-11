/*
 * meituan-009. 小团的装饰物
 *
 * https://leetcode-cn.com/problems/0VvYxa/
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// 妙啊 动态规划 dp[i][j] 代表长度为i 某位数字为j的个数
// 则 dp[i][j] = dp[i-1][k] k 为 j 的因数
// 为了计算的方便 可以采用 乘法 反过来累加  计算j 为 1 到 k 的倍数

int main () {
    const int  num = 998244353;
    int n, m;
    cin >> n >> m;
    // vector<vector<int>> dp(m, vector<int>(n+1, 0));
    // for (int i = 1; i <= n; i++)
    //     dp[0][i] = 1;    
    // for (int i = 1; i < m; i++) {
    //     for (int k = 1; k <= n; k++) {
    //         for (int j = k; j <= n; j+=k) {
    //             dp[i][j] += dp[i-1][k];
    //             dp[i][j] %= num;
    //         }
    //     }
    // }
    // int ans = 0;
    // for (int i = 1; i <= n; i++)
    //     ans = (ans + dp.back()[i]) % num;
    // cout << ans << endl;
    
    // 压缩为1维
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++) {
        vector<int> temp(n, 0);
        for (int k = 1; k <= n; k++) {
            for (int j = k; j <= n; j+=k) {
                temp[j-1] += dp[k-1];
                temp[j-1] %= num;
            }
        }
        swap(temp, dp);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = (ans + dp[i]) % num;
    cout << ans << endl;
    
    return 0;
}


// 输入：
// 4 2
// 输出：8
// 解释[1,1],[1,2][1,3][1,4][2,2][2,4][3,3][4,4]共8种。
