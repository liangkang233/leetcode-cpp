/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    // 求 [1,n) 范围内质数个数 可以采用此方法
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> prime(n, true) ;
        int count = n - 2; //去掉不是质数的1 和范围外的n
        for(int i = 2; i < n; ++i){
            if (prime[i]) {
                for (int j = 2*i; j < n; j += i){ // 将i的整数倍删除
                    if (prime[j]) {
                        prime[j] = false;
                        --count;
                    }
                }
            }
        }
        return count;
    }
};
// @lc code=end

// 优化版本
int countPrimes1(int n) {
    if (n <= 2) return 0;
    vector<bool> prime(n, true);
    int i = 3, sqrtn = sqrt(n), count = n / 2;  // i>=3的偶数一定不是质数
    for (int i = 3; i <= sqrtn; i+=2) {
        if(prime[i]) { 
        // 只对当前是未被标记的质数才进行 平方后累加2i的数设定为合数 减少重复遍历 
        // i为3开始的奇数 进入合数统计时 +i必定为偶数数没必要遍历 已经提前把偶数个数减少了
            for (int j = i*i; j < n; j += 2*i){
            // j不断 + 2i 为了避免偶数 的遍历
                if (prime[j]) {
                    --count ;
                    prime[j] = false;
                }
            }
        }
    }
    return count;
}