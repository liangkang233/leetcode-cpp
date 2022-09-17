/*
 * @lc app=leetcode.cn id=1413 lang=cpp
 *
 * [1413] 逐步求和得到正数的最小值
 */

// @lc code=start
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minX = nums[0], sum = minX;
        for(int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            minX = min(sum, minX);
        }
        return max(1, -minX+1);
    }
};
// @lc code=end

