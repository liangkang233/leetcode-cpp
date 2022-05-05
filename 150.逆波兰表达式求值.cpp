/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

#include <vector>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        if(tokens.size() == 1)
            return stoi(tokens.front());
        for (int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                int temp = st.top();
                st.pop();
                st.top() += temp;
            } else if(tokens[i] == "-") {
                int temp = st.top();
                st.pop();
                st.top() -= temp;
            } else if(tokens[i] == "*") {
                int temp = st.top();
                st.pop();
                st.top() *= temp;
            } else if(tokens[i] == "/") {
                int temp = st.top();
                st.pop();
                st.top() /= temp;
            } else {
                st.push(stoi(tokens[i]));
            }
            // cout << st.top() << endl;
        }
        return st.top();
    }
};
// @lc code=end
// ["18"]
// ["3","11","+","5","-"]
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
