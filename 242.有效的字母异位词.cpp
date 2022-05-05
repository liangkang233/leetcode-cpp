/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include <iostream>
#include <string>
using namespace std;


// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        int record_s[26] = {0}, record_t[26] = {0};
        for (int i = 0; i < s.size(); i++)
            record_s[s[i]-'a']++;
        for (int i = 0; i < t.size(); i++)
            record_t[t[i]-'a']++;
        for (int i = 0; i < 26; i++) {
            if(record_s[i] != record_t[i])
                return false;
        }
        return true;
    }
};
// @lc code=end