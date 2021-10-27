/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
// 动态规划 时间n 空间n
    int longestValidParentheses(string s) {
        int len = s.length(), maxn = 0;
        vector<int> table(len+1, 0);
        // 记录以table[i]为长度的子字符串的 符合题意括号长度
        for (int i = 1; i < len; i++) {
            if (s[i] == '(') //形如 XXXX(
                continue;
            if (s[i-1] == '(') //形如 XXX() 
                table[i+1] = table[i-1] + 2;
            else if (i-1-table[i] >= 0 && s[i-1-table[i]] == '(') //形如 XXX))
                table[i+1] = table[i] + 2 + table[i-1-table[i]];
            maxn = max(table[i+1], maxn);
        }
        return maxn;
    }
};
// @lc code=end

//栈 时间n 空间n   栈的最底层相当于上次的最后一个右括号的下标
/* 对于遇到的每个 \text{‘(’}‘(’ ，我们将它的下标放入栈中
对于遇到的每个 \text{‘)’}‘)’ ，我们先弹出栈顶元素表示匹配了当前右括号：
如果栈为空，说明当前的右括号为没有被匹配的右括号，我们将其下标放入栈中来
更新我们之前提到的「最后一个没有被匹配的右括号的下标」
如果栈不为空，当前右括号的下标减去栈顶元素即为「以该右括号为结尾的最长有效括号的长度」 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    maxans = max(maxans, i - stk.top());
                }
            }
        }
        return maxans;
    }
};

// 不需额外空间的计数器 时间2n 空间1 （正序扫一遍 逆序再扫一遍）可以参考32括号题
// 正序只会计入类似这样的值 XXXX(((), 逆序只会计入类似这样的值 XXXX())))
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = (int)s.length() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = max(maxlength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
};
