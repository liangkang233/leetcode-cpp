/*
 * @lc app=leetcode.cn id=1332 lang=cpp
 *
 * [1332] 删除回文子序列
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    // 删除的子序列不一定是连续的 即baabb 可以删bbb 再删aa 案例给的在误导
    // 如果非回文 删干净a之后再全部删干净b即可 (return 2), 否则删除这个回文(return 1)
    int removePalindromeSub(string s) {
        int n = s.size();
        for (int i = 0; i < n/2; i++) {
            if(s[i] != s[n-i-1])
                return 2;
        }
        return 1;
    }
};
// @lc code=end

// "abababababbbbbba"\n
