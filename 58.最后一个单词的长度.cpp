/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0, temp = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if(temp != 0)
                    ans = temp;
                temp = 0;
            }
            else
                temp++;
        }
        return temp!=0 ? temp : ans;
    }
};
// @lc code=end
