/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// 和 53题一样的动态规划 此处维护两个值 一个最小值 一个最大值 (不一定正负数)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], last_min = ans, last_max = ans;
        for(int i = 1; i < nums.size(); i++) {
            int t1 = last_max, t2 = last_min;
            last_max = max(nums[i], max(nums[i]*t1, nums[i]*t2));
            last_min = min(nums[i], min(nums[i]*t1, nums[i]*t2));
            // cout << last_max << " " << last_min << " " << ans << endl;
            ans = max(ans, last_max);
        }
        return ans;
    }
};
// @lc code=end

// [-4,-3,-2]\n