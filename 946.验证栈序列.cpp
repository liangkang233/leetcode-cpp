/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

// 最近笔试倒是经常做验证栈的题

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;
        while (i < pushed.size()) {
            st.push(pushed[i++]);
            while(!st.empty() && st.top() == popped[j]) {
                j++;
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

