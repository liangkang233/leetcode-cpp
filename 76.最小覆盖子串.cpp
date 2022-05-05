/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        if(s.size() >= t.size()) {
            int n = 0; // 统计字符匹配个数
            unordered_map<char, int> record; // 标记数组 s中有的数字标记个数
            for (int i = 0; i < t.size(); i++)
                record[t[i]]++;
            for (int i = 0, j = 0; i < s.size(); i++) {
                if(record.find(s[i]) != record.end()) {
                    if(record[s[i]] > 0)
                        n++;
                    record[s[i]]--;
                }
                while (n >= t.size()) { // 超出预期 可以不断缩减窗口左边界
                    if(ans.empty() || i-j+1 < ans.size())
                        ans = s.substr(j, i - j + 1);
                    if(record.find(s[j]) != record.end()) {
                        if(record[s[j]] >= 0)
                            n--;
                        record[s[j]]++;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
// "a"\n"a"\n
// "aasdfjkhweugkerkjhuihHJGHDUHSAGDewjhauiehfuiajwlkeflkhufyhaiuhwrgjk"\n"dfhejwef"\n
