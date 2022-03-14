/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int nums[1001]={0};
        for (int i = 0; i < nums1.size(); i++)
            nums[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++) {
            if(nums[nums2[i]] > 0) {
                nums[nums2[i]] = 0;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

// [4,9,5]\n[9,4,9,8,4]\n