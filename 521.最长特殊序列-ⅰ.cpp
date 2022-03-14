/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
// 理解错题目 只要其中一个为另一个的子序列 会返回长的string 长度，其他情况非子序列也是 返回长的
// 因为长字符串必定不会 可以由较短的字符串表达出
// 所以 只有两个相等时 才会返回 -1
class Solution {
public:
    int findLUSlength(string a, string b) {
        // int ans = 0, amax = 0, bmax = 0;
        // int myset[26] = {0}, myset1[26] = {0};
        // for (int i = 0; i < a.size(); i++)
        //     myset[a[i] - 'a'] ++;
        // for (int i = 0; i < b.size(); i++)
        //     myset1[b[i] - 'a'] ++;
        // for (int i = 0; i < 26; i++) {
        //     // cout << myset[i] << " " << myset1[i] << endl;
        //     if(myset[i] != myset1[i]) 
        //         continue;
        //     if(myset[i]>0)
        //         amax+=myset[i];
        //     if(myset1[i]>0)
        //         bmax+=myset1[i];
        // }
        // ans = max(amax, bmax);
        // return ans==0 ? -1 : ans;
        if(a == b)
            return -1;
        return max(a.size(), b.size());
    }
};
// @lc code=end
// "abcd"\n"efg"\n
// "asd"\n"asddfg"\n
// "aefawfawfawfaw"\n"aefawfeawfwafwaef"\n
