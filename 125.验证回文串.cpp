/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.empty()) {
            const int ch = 'a' - 'A';
            int L = 0, R = s.size()-1;
            while (L < R) {
                if(!isalpha(s[L]) && (s[L] < '0' || s[L] > '9'))
                    L++;
                else if(!isalpha(s[R]) && (s[R] < '0' || s[R] > '9'))
                    R--;
                else {
                    char temp1 = islower(s[L]) ? s[L] - ch : s[L];
                    char temp2 = islower(s[R]) ? s[R] - ch : s[R];
                    // cout << temp1 << " " << temp2 << endl;
                    if(temp1 == temp2) {
                        L++;
                        R--;
                    }
                    else
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
// "A man, a plan, a canal: Panama"\n
// "race a car"\n
// "0P"\n

// 官方写的多优雅
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        int n = sgood.size();
        int left = 0, right = n - 1;
        while (left < right) {
           if (sgood[left] != sgood[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
