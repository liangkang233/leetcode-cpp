/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        // 匿名函数用法  这样做可减少内存的拷贝
        auto bin_find = [&](int a, int b) ->int {
            int i;
            while (a <= b) {
                i = (a + b) / 2;
                if (nums[i] < target)
                    a = i + 1;
                else if (nums[i] > target)
                    b = i - 1;
                else
                    return i;
            }
            return -1;
        };

        if (nums[0] <= nums[len - 1]) // <即k==0不转移，=即size==1  (普通二分)
            return bin_find(0, len - 1);

        int a = 0, b = len - 1, i;          // 特殊二分 先找到临界点
        while (a <= b) {
            i = (a + b) / 2;
            if (nums[i] < nums[i + 1]) {
                if (nums[i] >= nums[0])
                    a = i + 1;
                else
                    b = i - 1;
            }
            else
                break;
        }
        if (target < nums[0])
            return bin_find(i + 1, len - 1);
        return bin_find(0, i);
    }
};
// @lc code=end


// 跟官方的思路差不多，不过不用先找到最大临界值再二分 直接进行判断二分 
// 注意 边界 等于 问题
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) 
            return -1;
        else if (n == 1) 
            return nums[0] == target ? 0 : -1;

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;    // target判断是否为mid
            if (nums[0] <= nums[mid]) {             // 说明0到mid是升序
                if (nums[0] <= target && target < nums[mid])  // target在该升序中
                    r = mid - 1;
                else 
                    l = mid + 1;
            } 
            else {                                  // 说明mid到n-1是升序
                if (nums[mid] < target && target <= nums[n - 1])  // target在该升序中
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
        }
        return -1;
    }
};
