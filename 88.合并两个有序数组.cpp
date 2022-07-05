/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include<iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> t(nums1.begin(), nums1.begin()+m);
        int i1=0, i2=0;
        for (int i = 0; i < m+n; i++) {
            int a = i1 >= m ? INT_MAX : t[i1];
            int b = i2 >= n ? INT_MAX : nums2[i2];
            if(a > b) {
                nums1[i] = b;
                i2++;
            } else {
                nums1[i] = a;
                i1++;
            }

        }
    }
};
// @lc code=end
// [0]\n0\n[1]\n1
// [1]\n1\n[]\n0
// [2,0]\n1\n[1]\n1

// 空间O(1) 直接逆向 按照大的 遍历
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                cur = nums2[p2--];
            } else if (p2 == -1) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};