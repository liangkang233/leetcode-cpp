/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int record[26] = {0};
        for (int i = 0; i < s1.size(); i++)
            record[s1[i] - 'a']++;
        int n = 0;
        for (int i = 0, j = 0; i < s2.size(); i++) {
            if(record[s2[i]-'a'] == 0) {
                while(j <= i && record[s2[i] - 'a'] == 0) {
                    n--;
                    record[s2[j++] - 'a']++;
                }
            }
            n++;
            record[s2[i] - 'a']--;
            // cout << j << " " << i << " " << n << endl;
            if(n == s1.size())
                return true;
        }
        return false;
    }
};
// @lc code=end
// "ab"\n"eidboaoo"\n
