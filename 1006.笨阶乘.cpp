/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

#include <iostream>
#include <vector>
using namespace std;

// 做几次枚举 一般性的规律 */ +num -*/ +num -*/ +num -*/
// 且 */ 值为 (n+2)*(n+1)/n=>n+3+2/n 当n>2时 */ => n+3

// @lc code=start
class Solution {
public:
    int clumsy(int n) {
        const char xiao[5] = {1, 1, 2, 6, 7};    
        // xiao[n]对应后有几个数的值，n[0]是刚好n为4倍数的补齐（因为那四位数对应值不是-n-3）
        // 当即1 <= n <= 4 ,return 1、2、6、7   对于计算余数位置 0<=n<= 3 对应-1、-2、-6、-5
        // 余数为0,最后一个四位少减个1
        if (n > 4) {
            //前四位计算必为2n+2，中间每四位值为-4, 后面的为-xiao[n%4-1]
            return 2*n - 2 - 4*(n/4-1) - xiao[n%4];
        }
        else 
            return xiao[n];
    }
};
// @lc code=end

