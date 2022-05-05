/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 与第5题求最长回文子串相同
    int countSubstrings(string s) {
        int ans = s.size();
        vector<bool> dp(s.size(), true), temp(dp); // 压缩为1维
        // vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
        for (int i = 0; i < s.size(); i++) {
            for (int j = i-1; j >= 0; j--) { // 默认dp[i][i] 为 true
                if(dp[j+1] && s[i] == s[j]) {
                    temp[j] = true;
                    ans++;
                }
                else 
                    temp[j] = false;
            }
            // for (int j = 0; j <= i; j++) {
            //     if(temp[j])
            //         cout << 1 << " ";
            //     else
            //         cout << 0 << " ";
            // }
            // cout << "\n";
            swap(temp, dp);
        }
        return ans;
    }
};
// @lc code=end
// "askldjfiojhaiowuegihaseuihgaskdfjhjkagjhdkgjakljgkl"\n
// "aaaaaa"\n
// "ppppppppppppppppppptttttttttttttjasdkfhuiqyweuihfjsdhhhhhhhhhhhhffdddddddddddddddddddddiiiiiiiiiiiiiiiiiiiiiieeeeeeeeeeeeeeeelllllllll"\n
