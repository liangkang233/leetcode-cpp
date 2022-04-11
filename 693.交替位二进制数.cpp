/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool hasAlternatingBits(int n) {
        while (n > 0) {
            if(! (n&1 ^ (n>>1&1)) )
                return false;
            n = n >> 1;
        }
        return true;
    }
};
// @lc code=end
// 1\n
// 2147483647\n
