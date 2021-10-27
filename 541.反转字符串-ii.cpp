/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    void myrever(string& s, int l, int r) {
        char temp;
        while(l < r) {
            temp = s[l];
            s[l++] = s[r];
            s[r--] = temp;
        }
    }

    string reverseStr(string s, int k) {
        int i = 0, len = s.length();
        for (; i + k*2 <= len; i += k*2) {
            myrever(s, i, i+k-1);
        }
        myrever(s, i, min(i+k-1, len-1));
        return s;
    }
};
// @lc code=end

