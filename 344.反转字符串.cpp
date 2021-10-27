/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;
// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int i = 0, j = s.size()-1;
        while(i < j) {
            temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }
};
// @lc code=end

