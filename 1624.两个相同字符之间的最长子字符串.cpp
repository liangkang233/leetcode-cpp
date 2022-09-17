/*
 * @lc app=leetcode.cn id=1624 lang=cpp
 *
 * [1624] 两个相同字符之间的最长子字符串
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        unordered_map<char, int> mp;
        for (int r = 0; r < s.size(); r++) {
            if(mp.find(s[r]) == mp.end()) {
                mp[s[r]] = r;
            } else {
                ans = max(r-mp[s[r]]-1, ans);
            }
        }
        return ans;
    }
};
// @lc code=end

