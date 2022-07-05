/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// @lc code=start
// 时间复杂度 O(n) 由题意 区间的左右界为最小值 最大值
// 使用单调栈 改版做法 这里直接用 vector
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> st; //记录下标 映射值为 递增的 单调栈
        int L = 0, R = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) { // 寻找左边界
            while (!st.empty() && nums[st.back()] > nums[i])
                st.pop_back();
            st.push_back(i);
        }
        for (int i = 0; i < st.size() && st[i] == L; i++, L++);

        if(L == nums.size()) return 0;
        st = vector<int>();

        for (int i = nums.size() - 1; i >= 0; i--) { // 寻找右边界
            while (!st.empty() && nums[st.back()] < nums[i])
                st.pop_back();
            st.push_back(i);
        }
        for (int i = 0; i < st.size() && st[i] == R; i++, R--);
        return R - L + 1;
    }
};
// @lc code=end
// [1,2,3,4,5,6]\n
// [6,5,4,3,2,1]\n

// 直接暴力遍历 效果不好
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums1(nums);
        sort(nums1.begin(), nums1.end());
        int i = 0, j = nums.size() - 1;
        for (; i < nums.size() && nums1[i]== nums[i]; i++);
        if(i == nums.size())
            return i;
        for (; j >= 0 && nums1[j] == nums[j]; j--);
        return j - i + 1;
    }
};

// 官方答案简洁明了
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left = -1;
        // 若边界确定 则区间内所有值都大于左边界 小于右边界
        for (int i = 0; i < n; i++) { 
            // minn 反着遍历 确定左边界 如果比最小值大 更新左边界  否则更改最小值
            if (minn < nums[n - i - 1]) {
                left = n - i - 1;
            } else {
                minn = nums[n - i - 1];
            }
            // maxn 正向遍历 确定右边界 如果比最大值小 更新右边界  否则更改最大值
            if (maxn > nums[i]) {
                right = i;
            } else {
                maxn = nums[i];
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};