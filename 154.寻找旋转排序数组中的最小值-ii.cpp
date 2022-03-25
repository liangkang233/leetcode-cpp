/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// 使用二分法寻找最小值
class Solution{
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = (high + low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            else if(nums[pivot] > nums[high]) {
                low = pivot + 1;
            }
            else { //nums[pivot] == nums[high]   预防有重复元素
                high--;//由于high和pivot相等，左移high直到pivot能出结果
            }
        }
        return nums[low];
    }
};
// @lc code=end

// 允许重复会影响算法的时间复杂度吗?
// 答: 会有 最差会到O(n)