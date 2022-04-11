/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// 与198题差不多，多一个首尾相连的限制
class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        if(nums.size() <= 3) {
            for (int i = 0; i < nums.size(); i++)
                ans = max(ans, nums[i]);
            return ans;
        }

        int first = nums[0], second = max(nums[0], nums[1]); //不取最后一个
        for (int i = 2; i < nums.size()-1; i++) {
            int temp = second;
            second = max(first+nums[i], second);
            first = temp;
        }
        ans = second;
        // second = // 头尾皆取
        first = nums[1], second = max(nums[1], nums[2]); // 不取第一个
        cout << first << " " << second << endl;
        for (int i = 3; i < nums.size(); i++) {
            int temp = second;
            second = max(first+nums[i], second);
            first = temp;
        }
        return max(second, ans);
    }
};
// @lc code=end
// [0]\n
// [2,7,9,3,1]\n
// [1,3,1,3,100]\n
// [2,7,9,3,1,12,5,90,3,8,234,56,34,63,45,55,75,93,47,95,9]\n


// 官方 简洁
class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }
};