/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void mydfs(vector<string>& ans, string& digits, string& temp, int index, const char (*strs)[5]) {
        if(index >= digits.size()) {
            ans.push_back(temp);
            return;
        }
        int i = digits[index] - '2';
        for (int j = 0; j < 4 && strs[i][j] != ' '; j++) {
            temp.push_back(strs[i][j]);
            mydfs(ans, digits, temp, index+1, strs);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        const char strs[8][5] = {"abc ", "def ", "ghi ", "jkl ", "mno ", "pqrs", "tuv ", "wxyz"};
        vector<string> ans;
        string temp;
        if(digits.size() > 0)
            mydfs(ans, digits, temp, 0, strs);
        return ans;
    }
};
// @lc code=end
// "23"\n
// "2233"\n
// "2"\n
// ""\n