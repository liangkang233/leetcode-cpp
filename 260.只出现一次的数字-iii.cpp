/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
// 牛的牛的
// 遍历异或一遍，N = a ^ b N 肯定不为0 否则 a==b  根据N的某一位 将 整个数组分为两个部分 异或一遍即可出答案
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int N = 0, val1 = 0, bit;
        for (int i = 0; i < nums.size(); i++) { N ^= nums[i];}
        if(N==INT_MIN) bit = 1;
        else bit = N & (-N);
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] & bit)
                val1 ^= nums[i];
            // 最后 val2 等价于 val1 ^ N  因为N==val1^val2
            // else                  
            //     val2 ^= nums[i];
        }
        return vector<int> {val1, val1^N};
    }
};
// @lc code=end
// [0, -2147483648]
