/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

#include <iostream>
using namespace std;

// @lc code=start

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0, temp = x; //temp 代表 X^(2^i)
        int k = n;
        if(n < 0)
            k = -(n+1); //乘法比除速度快，进行转正, +1是为了防止INT_MIN转正溢出 
        for (int i = 0; i < 32 && k > 0; i++) {
            ans = k&1 ? ans*temp : ans;
            temp *= temp;
            k = k >> 1;
        }
        return n<0 ? 1/ans/x : ans;
    }
};
// @lc code=end
// 0.1\n2147483647\n
// 1.01\n-2147483648\n
// 1.1\n0\n
// 1.1\n-1\n
// -1.1\n-2\n 加负号测试总是显示默认测试案例

// 妙啊 直接long不考虑转正问题
class Solution {
public:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};
// 链接：https://leetcode-cn.com/problems/powx-n/solution/powx-n-by-leetcode-solution/

// 位运算 也是不考虑转正问题
class Solution {
public:
    double quickMul(double x, long long N) {
        double ans = 1.0;
        // 贡献的初始值为 x
        double x_contribute = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N % 2 == 1) {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans;
    }

    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};