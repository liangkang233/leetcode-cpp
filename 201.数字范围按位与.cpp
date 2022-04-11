/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

#include <iostream>
using namespace std;

// @lc code=start
// 最后的答案按照二进制中的 每个位 来计算
// 举例
// 0       0000
// 1       0001
// 2       0010
// 3       0011
// 4       0100
// 5       0101
// 6       0110
// 7       0111
// 8       1000
// 9       1001
// 10      1010
// 11      1011
// 12      1100
// 13      1101
// 14      1110
// 15      1111
// 16     10000
// https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/solution/shu-zi-fan-wei-an-wei-yu-by-leetcode-solution/
// 位运算 找规律 真的难想 
// 最后的答案即为二进制字符串的公共前缀再用零补上后面的剩余位。
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int temp = 0;
        while(left < right) {
            left = left>>1;
            right = right>>1;
            temp++;
        }
        // return temp == 0 ? left : left << temp;
        return left << temp;
    }
};
// @lc code=end