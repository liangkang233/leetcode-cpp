/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        int n = abs(num);
        string temp;
        do {
            temp.push_back( n%7 + '0');
            n /= 7;
        }
        while (n != 0);
        reverse(temp.begin(), temp.end());
        return num < 0 ? "-"+temp : temp;
    }
};
// @lc code=end

// -1\n