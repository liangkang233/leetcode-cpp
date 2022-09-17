/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last = INT_MIN, flag = 0;
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == last){
                flag++;
            } else {
                flag = 0;
                last = nums[i];
            }
            if(flag < 2)
                temp.push_back(nums[i]);
        }
        nums = temp;
        return nums.size();
    }
};
// @lc code=end

// 不使用额外空间的做法  注意题中是升序的
int removeDuplicates(vector<int>& nums) {
    int n = nums.size(), count = 0;
    for (int i = 2; i < n; i++)
        if (nums[i] == nums[i - 2 - count]) count++;
        else nums[i - count] = nums[i];
    return n - count;
}
