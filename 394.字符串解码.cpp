/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 一眼为栈 用dfs写的好看些
// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        string ans, temp;
        stack<pair<int, string>> st;
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] <= '9' && s[i] >= '0') { // 数字串
                while(s[i] <= '9' && s[i] >= '0') {
                    num = 10 * num + s[i++]-'0';
                } // 数字后 必定为 '['
                if(num == 0) num = 1;
                st.push(make_pair(num, ""));
                num = 0;
            }
            if(s[i] <= 'z' && s[i] >= 'a') { // 字母串
                while(s[i] <= 'z' && s[i] >= 'a') {
                    temp.push_back(s[i++]);
                }
                i--;
                if(!st.empty())
                    st.top().second += temp;
                else
                    ans += temp;
                temp = "";
            }
            if(s[i] == ']') {
                string t;
                for (int i = 0; i < st.top().first; i++)
                    t += st.top().second;
                st.pop();
                if(!st.empty()) {
                    st.top().second += t;
                } else {
                    ans += t;
                }
            }
        }
        return ans;
    }
};
// @lc code=end


class Solution {
public:
    string src; 
    size_t ptr;

    int getDigits() {
        int ret = 0;
        while (ptr < src.size() && isdigit(src[ptr])) {
            ret = ret * 10 + src[ptr++] - '0';
        }
        return ret;
    }

    string getString() {
        if (ptr == src.size() || src[ptr] == ']') {
            // String -> EPS
            return "";
        }

        char cur = src[ptr]; int repTime = 1;
        string ret;

        if (isdigit(cur)) {
            // String -> Digits [ String ] String
            // 解析 Digits
            repTime = getDigits(); 
            // 过滤左括号
            ++ptr;
            // 解析 String
            string str = getString(); 
            // 过滤右括号
            ++ptr;
            // 构造字符串
            while (repTime--) ret += str; 
        } else if (isalpha(cur)) {
            // String -> Char String
            // 解析 Char
            ret = string(1, src[ptr++]);
        }
        
        return ret + getString();
    }

    string decodeString(string s) {
        src = s;
        ptr = 0;
        return getString();
    }
};