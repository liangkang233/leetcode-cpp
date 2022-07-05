// https://www.nowcoder.com/practice/c215ba61c8b1443b996351df929dc4d4?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// 优雅写法 牛的

// 有括号的计算 递归下去，遇到符号位 则根据上次记录符号位 对数据放入栈中: 乘法 直接进行计算 加减法进行正负输入
class Solution {
public:
    int solve(string s) {
        int ans = 0, val = 0;
        char flag = '+';
        stack<int> st;
        for (int i = 0; i <= s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                val = 10 * val + s[i] - '0';                
            } else if (s[i] == '(') {
                int l = ++i;
                for (int count = 1; count>0; i++) {
                    if(s[i] == '(')
                        count++;
                    if(s[i] == ')')
                        count--;
                } i--;
                // cout << s.substr(l, i-l) << endl;
                val = solve(s.substr(l, i-l)); // 递归下去
            } else { // s[i] 为符号位 或s[i] 为末尾
                if(flag == '+') st.push(val);
                else if(flag == '-') st.push(-1 * val);
                else st.top() *= val;
                flag = s[i];
                val = 0;
            }
        }
        while(!st.empty()) {
            // cout << st.top() << endl;
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
