/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int nums[1001] = {0};
        for (int i = 0; i < nums1.size(); i++)
            nums[nums1[i]]++;
        for (int i = 0; i < nums2.size(); i++) {
            if(nums[nums2[i]] > 0) {
                nums[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

// [4,9,5]\n[9,4,9,8,4]\n

// https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/solution/jin-jie-san-wen-by-user5707f/
// 问题1 双指针 两边都排序 直接 int i,j  相等push ans, 否则小的那个小标++
// 问题2 哈希计数 就是我是用的方法
// 问题3 内存小归并排序后再双指针
