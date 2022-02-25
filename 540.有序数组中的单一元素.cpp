/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

#include <iostream>
#include <vector>
using namespace std;

// 忘记了题目中声明数组为有序 依此二分
// @lc code=start
class Solution {
public:
    // 标准二分法，判断数字是否配对
    // 若mid为奇 mid ^ 1 == mid + 1
    // 若mid为偶 mid ^ 1 == mid - 1
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (high - low) / 2 + low;
            if (nums[mid] == nums[mid ^ 1]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};
// @lc code=end

// 或者只对偶数下标 成对的查找
class Solution {
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int mid = (high - low) / 2 + low;
            mid -= mid & 1;
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } else {
                high = mid;
            }
        }
        return nums[low];
    }
};


// [0]\n
// [3,3,7,7,10,11,11]\n
// [3,3,7,7,1112,1112,1145]\n

class Solution {
public:
    // 首先想到的时间复杂度O(n) 空间复杂度O(1)
    int singleNonDuplicate(vector<int>& nums) {
        int num = 0;
        // 相同的数异或两次为0（会抵消） 例如1^2^1 = 2    
        for (int i = 0; i < nums.size(); i++)
            num ^= nums[i];
        return num; 
    }
};
