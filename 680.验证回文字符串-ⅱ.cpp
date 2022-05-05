/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool myvalidPalindrome(string s, int flag) {
        int L = 0, R = s.size() - 1;
        while (L < R) {
            if(s[L] != s[R]) {
                if(flag > 0 && (myvalidPalindrome(s.substr(L, R-L), flag-1) || myvalidPalindrome(s.substr(L+1, R-L), flag-1)))
                    break;
                return false;
            }
            L++;
            R--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        return myvalidPalindrome(s, 1); // flag 表示可删减的字符个数
    }
};
// @lc code=end

// "asdrdssa"\n
// "asdrdssar"\n
// "asdfasdfffdsasdf"\n
// "abc"\n