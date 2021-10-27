/*
 * @lc app=leetcode.cn id=779 lang=cpp
 *
 * [779] 第K个语法符号
 */

#include <iostream>
#include <vector>
using namespace std;


/* 多试几次易知以下规律：
每一行 前半段 和 后半段 刚好相反
每一行 前半段 等于 上一行
由此 每一行的 某一位 可以用通用的公式计算
*/

// @lc code=start
class Solution {
public:
    int kthGrammar(int n, int k) {
        // 使用二分法
        int ans = 0, temp = 1; //temp 表示2^n-1
        // for (int i = 1; i <= n-1; i++)
        //     temp *= 2; 优化为如下语句
        temp = 1 << n-1;         
        for (int i = 1; i <= n-1; i++) {
            temp = temp >> 1;    //temp /= 2;
            if (k > temp) {
                k -= temp;
                ans = !ans;
            }
        }
        return ans;
    }
};
// @lc code=end

// 上翻转法的递归写法
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        if (K <= 1 << N-2)
            return kthGrammar(N-1, K);
        return kthGrammar(N-1, K - (1 << N-2)) ^ 1; //这里的 ^1 等价 !
    }

// 其他做法 总结出规律，第 K 个数字是上一行第 (K+1) / 2 个数字生成的。
// 如果上一行的数字为 0，被生成的数字为 1 - (K%2)，如果上一行的数字为 1，被生成的数字为 K%2。
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        return (~K & 1) ^ kthGrammar(N-1, (K+1)/2);
    }
