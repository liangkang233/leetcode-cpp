/*
 * @lc app=leetcode.cn id=891 lang=cpp
 *
 * [891] 子序列宽度之和
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 放弃

// 古典排列组合 C1 + C1 + C2 + 。。。 CN = (1+1)^N = 2 ^ N
// 对于排序后的第i个元素，如果它是最大元素，其他元素只能左边选，一共有2^i种选法；
// 如果它是最小元素，其他元素只能右边选，一共有2^(n-i-1)种选法。
// 最小元素需要减去去 最大元素需要加上 所以最后答案 (2^i - 2^(N-i-1) ) * A[i] 的累加和 i=0,1....N 
// @lc code=start
class Solution {
public:
    const int LL = 1000000007;
    int sumSubseqWidths(vector<int>& nums) {
        long long ans = 0;
        sort(nums.begin(), nums.end());

        return int(ans % (LL));
    }
};
// @lc code=end
