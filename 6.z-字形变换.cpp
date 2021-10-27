/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

#include <iostream>
#include <string>

using namespace std;

// 看懂题目即可，用坐标硬解 无技巧

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        int len = s.length(), z_len = 2 * numRows - 2;
        if (z_len <= 0)
            return s;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < len ; j+=z_len) {
                ans.push_back(s[j]);
                int temp = (j / z_len + 1) * z_len - i;
                if (i > 0 && i < numRows-1 && temp < len)
                    ans.push_back(s[temp]);
            }
        }
        return ans;
    }
};
// @lc code=end

