/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include<iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 相同的数异或两次为0（会抵消） 例如1^2^1 = 2        
        int ans = 0;
        for (int num: nums) {
            ans ^= num;
        }
        return ans;
    }
};
// @lc code=end

