/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // a-z => 97-122; A-Z => 65-90
    // 判断是否为字符使用 isalpha()
    string reverseOnlyLetters(string s) {
        int start=0, end=s.size()-1;
        while (start < end) {
            while (start < s.size() && !isalpha(s[start]) )
                start++;
            while (end >= 0 && !isalpha(s[end]) )
                end--;
            if(start < end)
                swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};
// @lc code=end

// 理解错题目 以为是将字母字符反转 类似 qwe-qe,io => ewq-eq,oi
class Solution {
public:
    // a-z => 97-122; A-Z => 65-90
    string reverseOnlyLetters(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            // if(('A'<=s[i]&&'Z'>=s[i]) || ('a'<=s[i] && 'z'>=s[i])) {
            if(isalpha(s[i])) {
                start = i;
                while(i < s.size() && isalpha(s[i]))
                    i++;
                reverse(s.begin()+start, s.begin()+i);
                i--;
            }
        }
        return s;
    }
};

