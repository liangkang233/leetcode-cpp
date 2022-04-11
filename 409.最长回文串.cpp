/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        char mymap[128] = {0};
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            mymap[s[i]]++;
            if(mymap[s[i]] == 2) {
                mymap[s[i]] = 0;
                ans+=2;
            }
        }
        if(ans < s.size())
            ans++;
        return ans;
    }
};
// @lc code=end
// "a"\n
