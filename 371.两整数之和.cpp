/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // (a&b) << 1  // 都为1需要进位
    // (a^b)       // 不同为1保留值
    // 由于计算机中处理 负数使用补码 所以无论正负数 相加 都可以用 普通正数加法来做处理
    int getSum(int a, int b) {
        // int a1 = (a&b) << 1, b1 = a^b; 直接(a&b) << 1 遇到 -1 + 1 类似的会溢出
        unsigned int a1 = (unsigned int)(a&b) << 1;
        int b1 = a^b;
        if( (a1 & b1) == 0) // 没有需要进位的
            return (a1 | b1);
        return getSum(a1, b1);
    }
};
// @lc code=end

// 12\n78\n
// -1\n1\n
// 120\n780\n
// -120\n780\n
// 180\n-780\n
// -890\n-23\n