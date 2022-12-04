/* 面试题 01.02. 判定是否互为字符重排
给定两个字符串 s1 和 s2，请编写一个程序，
确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

示例 1：
    输入: s1 = "abc", s2 = "bca"
    输出: true

示例 2：
    输入: s1 = "abc", s2 = "bad"
    输出: false

说明：
    0 <= len(s1) <= 100
    0 <= len(s2) <= 100 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int mp[26] = {0};
        for(int i = 0; i < s1.size(); i++) {
            mp[s1[i]-'a']++;
        }
        for(int i = 0; i < s2.size(); i++) {
            if(mp[s2[i]-'a'] == 0) return false;
        }
        return true;
    }
};