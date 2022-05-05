/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i+1] = prefix[i] + nums[i];
        for (int i = 0; i < n; i++) {
            if(prefix[i] == prefix[n] - prefix[i+1])
                return i;
        }
        return -1;
    }
};
// @lc code=end
// [1, 2, 3]\n
// [2, 1, -1]\n