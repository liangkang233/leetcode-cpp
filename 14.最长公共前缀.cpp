/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        for (int j = 0; j < strs[0].size(); j++) { //题中限定最长长度为200
            for (int i = 1; i < strs.size(); i++) {
                if(j >= strs[i].size() || strs[i][j] != strs[0][j])
                    return ans;
            }
            ans.push_back(strs[0][j]);
        }
        return ans;
    }
};
// @lc code=end

// ["a"]\n
// ["", "as", "as"]\n
// ["qw", "qwe", ""]\n