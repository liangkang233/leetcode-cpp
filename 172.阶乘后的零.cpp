/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        // 2的因数一定比5的因数多，所以只要求n阶乘中所有数的5的因数即可
        int ans = 0;
        while (n >= 5) {
            n = n / 5;
            ans += n;
        }
        return ans;
    }
};
// @lc code=end

