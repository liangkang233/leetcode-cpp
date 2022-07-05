/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        string temp;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                temp.push_back(s[i]);
            else {
                if(s[i] == ')') {
                    if(temp.empty() || temp.back() != '(')
                        return false;
                } else if (s[i] == '}') {
                    if(temp.empty() || temp.back() != '{')
                        return false;
                } else {
                    if(temp.empty() || temp.back() != '[')
                        return false;
                }
                temp.pop_back();
            }
        }
        return temp.empty();
    }
};
// @lc code=end
// "([)]"\n
// "()[]}{"\n

// 理解错题意
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
            if (mp['('] < mp[')'] || mp['{'] < mp['}'] || mp['['] < mp[']'])
                return false;
        }
        return (mp['('] == mp[')'] && mp['{'] == mp['}'] && mp['['] == mp[']']);
    }
};

// 二刷
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp;
        stack<char> st;
        mp[')'] = '('; mp[']'] = '['; mp['}'] = '{';
        for (int i = 0; i < s.size(); i++) {
            if(mp.find(s[i]) == mp.end()) {
                st.push(s[i]);
            } else if(!st.empty() && st.top() == mp[s[i]] ) {
                st.pop();
            } else {
                return false;
            }
        }
        return st.empty();
    }
};