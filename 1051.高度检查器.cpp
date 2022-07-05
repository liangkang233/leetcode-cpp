#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=1051 lang=cpp
 *
 * [1051] 高度检查器
 */

// @lc code=start
class Solution {
public:
    // 随机数版本 自实现快排
    void mysort(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int p = rand() % (right - left + 1) + left;
        swap(nums[left], nums[p]);
        int pivot = nums[left];
        int l = left, r = right;
        while(l < r){
            while(l<r && nums[r] >= pivot) r--;
            nums[l] = nums[r];
            while(l<r && nums[l] <= pivot)l++;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        mysort(nums, left, l-1);
        mysort(nums, l+1, right);
    }
    int heightChecker(vector<int>& heights) {
        int ans = heights.size();
        vector<int> t(heights);
        mysort(t, 0, t.size()-1);        
        for (int i = 0; i < heights.size(); i++) {
            if(heights[i] == t[i])
                ans--;
        }
        return ans;
    }
};
// @lc code=end
// [8,91,23,87,6,78,9,23,6,5,78,1,6,5,6,7,86,5,1,8,7,6,34,9,8,1,7,5,8,7,67,8,9,1,3,6,6,7,5,16,7,4,5,6,7,34,1,5,7,8]
