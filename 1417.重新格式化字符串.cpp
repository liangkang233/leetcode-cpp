/*
 * @lc app=leetcode.cn id=1417 lang=cpp
 *
 * [1417] 重新格式化字符串
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    string reformat(string s) {
        string ans(s), s1, s2;
        for (int i = 0; i < s.size(); i++) {
            if(isalpha(s[i])) {
                s1.push_back(s[i]);
            } else {
                s2.push_back(s[i]);
            }
        }
        if(s1.size() < s2.size()) swap(s1, s2);
        if(s1.size() - s2.size() > 1) return "";
        for (int i = 0, i1 = 0, i2 = 0; i < ans.size(); i++) {
            if(i & 1) {
                ans[i] = s2[i2++];
            } else {
                ans[i] = s1[i1++]; // s1 多些
            }
        }
        return ans;
    }
};
// @lc code=end