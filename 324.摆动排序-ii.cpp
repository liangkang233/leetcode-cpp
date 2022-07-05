/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.cn/problems/wiggle-sort-ii/solution/bai-dong-pai-xu-ii-by-leetcode-solution-no0s/
// 摆动排序 直接开摆   用的方法1来做吧
// 注意此处 构造时不可用如下方法 

// @lc code=start
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(), v.end());
        // 为了避免重复的数字 放入数顺序使用 逆序的添加
        int n = nums.size(), j = n - 1;
        for (int i = 1; i < n; i+=2) {
            nums[i] = v[j--];
        }
        for (int i = 0; i < n; i+=2) {
            nums[i] = v[j--];
        }
    }
};
// @lc code=end
// [1,3,2,2,3,1]

// 官解的摆动 法1 不好理解
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        int x = (n + 1) / 2;
        // k 赋值逆序的值
        for (int i = 0, j = x - 1, k = n - 1; i < n; i += 2, j--, k--) {
            nums[i] = arr[j];
            if (i + 1 < n) {
                nums[i + 1] = arr[k];
            }
        }
    }
};