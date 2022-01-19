/*
 * @lc app=leetcode.cn id=1716 lang=cpp
 *
 * [1716] 计算力扣银行的钱
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // 直接递归深度会很大 重复计算也很多
    // 等差数列求和 某一周值为 7*(k-1) + 28 前k项和为 28*k + (k-1)*k*7/2
    // 第k周的起始值为k, 某一天的值为 k+i 前i项和 为 k*i + i*(i+1)/2
    int totalMoney(int n) {
        int k = n / 7, y = n - 7 * k;
        return 28*k + (k-1)*k*7/2  + k*y + y*(y+1)/2;
    }
};
// @lc code=end

