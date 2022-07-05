/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 不使用额外空间的做法 双指针
    void duplicateZeros(vector<int>& arr) {
        int i = 0, j = 0;
        for (; j < arr.size(); i++, j++) {
            if(arr[i] == 0 && j < arr.size() - 1) {
                arr[i] = -1; //代表该元素会重复两次 0
                j++;
            }
        }
        j--; i--;
        while (j >= 0) {
            if(arr[i] == -1) {
                arr[j--] = 0;
                arr[j--] = 0;
                i--;
            } else {
                arr[j--] = arr[i--];
            }
        }
    }
};
// @lc code=end
// [1,0,2,3,0,0,5,0]
