/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

#include <vector>
#include <iostream>
#include <string>
using namespace std;

// kmp 实现 strstr

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        vector<int> next(needle.size(), -1);
        for (int i = -1, j = 1; j < needle.size(); j++) {
            while (i!=-1 && needle[i+1] != needle[j])
                i = next[i];
            if(needle[i+1] == needle[j])
                i++;
            next[j] = i;
        }
        for(int i = -1, j = 0; j < haystack.size(); j++) {
            while (i!=-1 && needle[i+1] != haystack[j])
                i = next[i];
            if(needle[i+1] == haystack[j])
                i++;
            if(i == needle.size() - 1)
                return j-i;
        }
        return -1;
    }
};
// @lc code=end

