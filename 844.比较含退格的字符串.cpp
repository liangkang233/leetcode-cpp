/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;
// 想用双指针做的根shit一样，tnnd 错了好几次

// @lc code=start
class Solution {
public:
    void next(int& index, const string& str) {
        int flag = 0;
        while(index >= 0 && (flag > 0 || str[index] == '#')) {
            flag += str[index] == '#' ? 1 : -1;
            index--;
        }
    }
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1;
        for ( ; i>=0 || j >=0; i--, j--) {
            next(i, s);
            next(j, t);
            if(i < 0 || j < 0) {
                if(i >= 0 || j >= 0)
                    return false;
                continue;
            }
            if(s[i] != t[j])
                return false;
        }
        return true;
    }
};
// @lc code=end
// ""ui#####"\n"####""
// ""uiasd###"\n"uity##dsysu#####""
// ""bxj##tw"\n"bxo#j##tw""
// ""nzp#o#g"\n"b#nzp#o#g""
// ""nzp#o#g"\n"ab#nzp#o#g""

// 用栈不香吗
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return build(S) == build(T);
    }

    string build(string str) {
        string ret;
        for (char ch : str) {
            if (ch != '#') {
                ret.push_back(ch);
            } else if (!ret.empty()) {
                ret.pop_back();
            }
        }
        return ret;
    }
};