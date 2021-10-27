/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include <iostream>
using namespace std;

/*
    复习关于二进制数的知识：
    正数是符号位0 和 原码 ，负数是符号位1 和 补码（反码+1）
    所以8位正数范围包含[0-127] 负数范围为[-128， -1]  
    其中1000 0000(b)为-0即-128, 1111 1111(b)为-1

    // 这道题目很多坑 水平不好
    //  -A 会编译器优化为算补码所以INT_MIN(即为-2147483648)的宏定义为(-2147483647-1)
    // 另一种写法是int(-2147483648)
    // 此外VS测试中0x80000000可以用， 在leetcode中无法用 会报错说是int 无法与之比较 要强转

    // 总之这道题没什么意思 辣鸡
*/

// @lc code=start
class Solution {
public:
    // 0x80000000 = -2^31 ;
    // 0x7fffffff = 2^31 - 1  = 2147483647; 
    unsigned int myabs(int i) {
        if (i == (-2147483648))
            return (-2147483648);
        else if (i < 0)
            return -i;
        else 
            return i;
    }
    int divide(int dividend, int divisor) {
        if (dividend == 0)
            return 0;
        // else if (dividend == -2147483648 && divisor == -1)
        //     return 0x7fffffff;  //越界
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        unsigned int a, b, c = 0;
        a = myabs(dividend);
        b = myabs(divisor);

        for (int i = 31; i >= 0; i--) {
            if ((a >> i) >= b) {
                a -= (b << i);
                c += (1 << i);
            }
        }
        if (c == 0x80000000)
            return int(0x80000000);
        else 
            return ((dividend ^ divisor) >= 0) ? int(c) : -int(c);
    }
};
// @lc code=end

