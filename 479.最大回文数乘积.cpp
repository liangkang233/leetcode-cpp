/*
 * @lc app=leetcode.cn id=479 lang=cpp
 *
 * [479] 最大回文数乘积
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int largestPalindrome(int n) {
        long long ans;
        if(n == 1)  return 9;
        int MAX = pow(10, n) - 1, MIN = pow(10, n-1) - 1;   // n位数的最大值(可取) 最小值(不可取)
        for (int L = MAX; L > MIN; L--) {                   // L 为 n位数相乘的左半部分
            ans = L;
            for (int R = L; R > 0; R /= 10)
                ans = 10 * ans + R % 10;
            for (long long k = MAX; k*k >= ans; k--) {      // 找寻因数 其中一个因数必定大于 sqrt ans
            // 这里的优化方案是找因数从大往小找
                if(ans % k == 0) {
                    // cout << ans << " " << k << endl;
                    return ans % 1337;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

// 打表 反正 n 只有 1-8
class Solution {
public:
    int largestPalindrome(int n) {
        vector<int> ans {9,987,123,597,677,1218,877,475};
        return ans[n-1];
    }
};
