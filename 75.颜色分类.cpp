/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
// 类似快排的思路，因为数据只有 0 1 2 小于1的排左边 大于1的排右边 只用遍历一次
// 具体实现不能用 mysort 因为那个排序只能左右区间 大于等于 或小于等于的 顺序会不对 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 记录下次该转移的 0 1位置 所以 0 1一开始可以粘连一起 即 P0 P1 指针
        int P0 = 0, P1 = 0; 
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == 2)
                continue;
            if(nums[i] == 0) {
                swap(nums[P0], nums[i]);
                if(P0 < P1)
                    swap(nums[P1], nums[i]);
                P0++;
            }
            else // nums[i] == 1
                swap(nums[P1], nums[i]);
            P1++;
        }
    }
};
// @lc code=end
// [2,2,2,0,0,2,1]\n
// [1,1,2,2,1,2,1,0,1,1,2,2,1,2,1,0]\n

// 自实现归并版 快排
class Solution {
public:
    int mysort(vector<int>& nums, int L, int R) {
        int pivot = nums[L];
        while(L < R) {
            while (L < R && nums[R] >= pivot)
                R--;
            nums[L] = nums[R];
            while (L < R && nums[L] <= pivot)
                L++;
            nums[R] = nums[L];
        }
        nums[L] = pivot;
        return L;
    }
    void quick_sort(vector<int>& nums, int L, int R) {
        if(L >= R)
            return;
        int mid = mysort(nums, L, R);
        quick_sort(nums, L, mid);
        quick_sort(nums, mid+1, R);
    }
    void sortColors(vector<int>& nums) {
        quick_sort(nums, 0, nums.size()-1);
    }
};

// 单指针统计个数
// 我们可以考虑对数组进行两次遍历。在第一次遍历中，我们将数组中所有的 0 交换到数组的头部。
// 在第二次遍历中，我们将数组中所有的 1 交换到头部的 0 之后。此时，所有的 2 都出现在数组的尾部，这样我们就完成了排序。
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
        for (int i = ptr; i < n; ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[ptr]);
                ++ptr;
            }
        }
    }
};