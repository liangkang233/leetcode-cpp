/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

// @lc code=start
// 空间 O(1) 时间O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) { // 将 1-size 的值 放到对应 下标
            int t = nums[i];
            // 加临时值替换 防止类似 [3,4,-1,1] 前面的篡改了后面的元素
            while (t > 0 && t <= nums.size() && t != nums[t-1]) { 
                int temp = nums[t-1];
                nums[t-1] = t;
                t = temp;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] != i+1)
                return i+1;
        }
        return nums.size() + 1;
    }
};
// @lc code=end
// [3,4,-1,1]\n
// [1,2,3,4]\n
// [-1,-2,-3,-123,3,3,4,5,6,2,1,9]\n

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> ms(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); i++) {
            if(ms.find(i) == ms.end())
                return i;
        }
        return nums.size() + 1;
    }
};