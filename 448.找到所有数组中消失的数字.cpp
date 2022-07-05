/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// 类似题 287
// 不使用额外空间就只能对原数组标记更改 遍历过的值将值换为对应下标标记为负数
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                ans.push_back(i+1); // 注意 不是nums[i]
        }
        return ans;
    }
};
// @lc code=end

