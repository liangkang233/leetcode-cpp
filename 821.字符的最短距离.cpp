/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size()), record{-100000};
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == c)
                record.push_back(i);
        }
        record.push_back(INT_MAX); // record 记录c的位置与上下限
        for (int i = 0, j = 1; i < s.size(); i++) {
            ans[i] = min(i - record[j-1], record[j] - i);
            if(i == record[j])
                j++;
        }
        return ans;
    }
};
// @lc code=end

