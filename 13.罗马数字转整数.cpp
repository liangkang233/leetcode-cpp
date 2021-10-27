/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int stoi(char str) {
        switch (str) {
            case 'I' :  return 1;
            case 'V' :  return 5;
            case 'X' :  return 10;
            case 'L' :  return 50;
            case 'C' :  return 100;
            case 'D' :  return 500;
            default : return 1000; // M
        }
    }

    int romanToInt(string s) {
        int len = s.length();
        // vector<int> num(len, 1);
        int ans = stoi(s[len-1]), last = ans;
        for (int i = len - 2; i >= 0; i-- ) {
            int temp = stoi(s[i]);
            ans += temp<last ? -temp : temp;
            last = temp;
        }
        return ans;
    }
};
// @lc code=end

