/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    const char str[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    const int nums[7] = { 1,   5,   10,  50, 100, 500, 1000};
    
    string intToRoman(int num) {
        string ans = "";
        for (int i = sizeof(nums)/sizeof(int) - 1; i >= 0; i--) {
            int temp = num / nums[i];
            if (temp == 4) {
                ans += str[i];
                ans += str[i+1];
            }
            else if (i-1 >=0 && num/nums[i-1] == 9 ) {
                ans += str[i-1];
                ans += str[i+1];
                num %= nums[i-1];
                continue;
            }
            else {
                for (int j = 0; j < temp; j++)
                    ans += str[i];
            }
            num %= nums[i];
        }
        return ans;
    }
};
// @lc code=end

// 官方的硬件编码，回想起本科数字电路。。
const string thousands[] = {"", "M", "MM", "MMM"};
const string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

class Solution {
public:
    string intToRoman(int num) {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] + tens[num % 100 / 10] + ones[num % 10];
    }
};


// 法2  推荐些
const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        for (const auto &[value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }
};
