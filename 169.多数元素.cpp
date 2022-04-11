/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;


// 投票法正确思路：不妨假设整个数组的众数记做a，则最初的数组中a的数量大于其余所有数。
// 当采用count计数的时候有两种情况：
// 1）假设 ans 等于a，则当 count 从1变为0的过程，
//    此区间内a的数量等于其余数的数量，因此以count=0为分界线，数组右端部分的众数仍然为a
// 2）假设 ans 不等于a，则当 count 从1变为0的过程，
//    此区间内a的数量小于等于其余数的数量，因此以count=0为分界线，数组右端部分的众数仍然为a
// 因此，以count=0可以将整个原始数组分为若干部分，count=0右端部分的数组中的众数永远是a，最终必然会筛选出a

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(count == 0)
                ans = nums[i];
            if(ans == nums[i])
                count++;
            else
                count--;
        }
        return ans;
    }
};
// @lc code=end

// 分治法
class Solution {
    int count_in_range(vector<int>& nums, int target, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; ++i)
            if (nums[i] == target)
                ++count;
        return count;
    }
    int majority_element_rec(vector<int>& nums, int lo, int hi) {
        if (lo == hi)
            return nums[lo];
        int mid = (lo + hi) / 2;
        int left_majority = majority_element_rec(nums, lo, mid);
        int right_majority = majority_element_rec(nums, mid + 1, hi);
        if (count_in_range(nums, left_majority, lo, hi) > (hi - lo + 1) / 2)
            return left_majority;
        if (count_in_range(nums, right_majority, lo, hi) > (hi - lo + 1) / 2)
            return right_majority;
        return -1;
    }
public:
    int majorityElement(vector<int>& nums) {
        return majority_element_rec(nums, 0, nums.size() - 1);
    }
};

// 哈希表
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
        int majority = 0, cnt = 0;
        for (int num: nums) {
            ++counts[num];
            if (counts[num] > cnt) {
                majority = num;
                cnt = counts[num];
            }
        }
        return majority;
    }
};

// 排序
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

