/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include <iostream>
#include <vector>
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

// https://leetcode-cn.com/problems/xoh6Oh/solution/zheng-shu-chu-fa-by-leetcode-solution-3572/
class Solution {
public:
    // 如果结果溢出 返回 2^31-1   大体思路 用加法 来做除法
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX; // 溢出转为特定值
        if(divisor == INT_MIN) // divisor为最小值时防止溢出
            return dividend == INT_MIN ? 1 : 0;
        int a = dividend > 0 ? -dividend : dividend; // a b 皆转为负数
        int b = divisor > 0 ? -divisor : divisor;
        int ans = 0;
        vector<int> temp{b}; // 不能有除法 乘法 所以只能用加法 做倒序
        // while (a <= temp.back() + temp.back()) // 防止溢出 用下式
        while (a - temp.back() <= temp.back())
            temp.push_back(temp.back() + temp.back());
        for (int i = temp.size()-1; i>=0; i--) {
            if(a <= temp[i]) {
                ans += (1 << i);
                a -= temp[i];
            }
        }
        // 注意 ^ 优先级
        return (a ^ b) >= 0 ? ans : -ans; // 用除数符号位 判断是否为负数
    }
};