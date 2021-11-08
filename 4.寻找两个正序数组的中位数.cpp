/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if(size == 1) {
            if(!nums1.empty())
                return nums1[0];
            else
                return nums2[0];
        }
        int a = 0,b = 0;
        vector<int>::iterator num1 = nums1.begin();
        vector<int>::iterator num2 = nums2.begin();
        for (int i = 0; i <= size/2; i++) {
            a = b;
            if(num1 != nums1.end() && num2 != nums2.end()) {
                if(*num1 <= *num2) {
                    b = *num1;
                    num1++;
                }
                else {
                    b = *num2;
                    num2++;
                }
            }
            else if(num1 == nums1.end()) {
                b = *num2;
                num2++;
            }
            else {
                b = *num1;
                num1++;
            }
        }
        
        if (size % 2 == 0)
            return (a + b) / 2.0;
        else 
            return b;
    }
};
// @lc code=end

//上述为直接对比排序，下提出一种时间复杂度为O(log (m+n))的算法
// 其实无论size为奇数偶数，它的值都为 (num(size-1) + num(size)) / 2
// 利用二分法来做
class Solution1 {
public: 
    //使用二分法找到第k个的元素(排序从1开始)
    int findKth(vector<int> nums1, vector<int> nums2, int k) {
        int n1 = 0, n2 = 0; 
        int size1 = nums1.size();
        int size2 = nums2.size();
        for ( ; ;) {
            if(n1 == size1) 
                return nums2[n2 + k - 1];
            else if(n2 == size2) 
                return nums1[n1 + k - 1];
            else if(k == 1) 
                return min(nums1[n1], nums2[n2]);
            else {
                // key  无论如何排列 k都不会在两个数组中k/2中较小的那个位置
                int new_n1 = n1 + k/2 - 1 < size1 ? nums1[n1 + k/2 - 1] : 0X7FFFFFFF;
                int new_n2 = n2 + k/2 - 1 < size2 ? nums2[n2 + k/2 - 1] : 0X7FFFFFFF;
                if(new_n1 < new_n2) 
                    n1 += k/2;
                else 
                    n2 += k/2;
                k -= k/2; 
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        // 无论总个数是奇数还是偶数，其中位数都是第size/2 + 1 和 (size+1)/2)个元素的平均数
        return (findKth(nums1, nums2, size/2 + 1) + findKth(nums1, nums2, (size + 1)/2) ) / 2.0;
    }

};