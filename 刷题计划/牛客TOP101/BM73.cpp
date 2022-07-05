// https://www.nowcoder.com/practice/b4525d1d84934cf280439aeecc36f4af?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param A string字符串 
     * @return int整型
     */
    int getLongestPalindrome(string A) {
        int ans = 1;
        vector<bool> dp(A.size(), true); 
        // vector<vector<bool>> dp(A.size(), vector<bool>(A.size(), true)); // dp[j][i] 表示 j 到 i 是否为回文
        for (int r = 1; r < A.size(); r++) {
            for (int l = 0; l < r; l++) {
                // if(A[l] == A[r] && dp[r-1][l+1]) {
                // dp[i][j] = true;
                if(A[l] == A[r] && dp[l+1]) {
                    dp[l] = true;
                    // cout << l << " " << r << endl;
                    ans = max(r-l+1, ans);
                } else {
                    // dp[i][j] = false;
                    dp[l] = false;
                }
            }
        }
        return ans;
    }
};