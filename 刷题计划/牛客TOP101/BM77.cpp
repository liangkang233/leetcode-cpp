// https://www.nowcoder.com/practice/45fd68024a4c4e97a8d6c45fc61dc6ad?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return int整型
     */
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> st;
        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                if(!st.empty()) {
                    dp[i] = i-st.top()+1;
                    if(st.top() > 0)
                        dp[i] += dp[st.top()-1];
                    ans = max(ans, dp[i]);
                    st.pop();
                }
            }
//             cout << dp[i] << " ";
        }
        return ans;
    }
};