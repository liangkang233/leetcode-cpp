/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int L = 0, R = arr.size() - 1;
        while (L < R) {
            int mid = (L + R) / 2;
            if(arr[mid]<arr[mid+1]) {
                L = mid + 1;
            } else {
                R =mid;
            }
        }
        return L;
    }
};
// @lc code=end
// [1,2,3,4,5,2,1]\n
