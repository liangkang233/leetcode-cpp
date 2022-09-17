/*
 * @lc app=leetcode.cn id=1619 lang=cpp
 *
 * [1619] 删除某些元素后的数组均值
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    double trimMean(vector<int>& arr) {
        int ans = 0;
        sort(arr.begin(), arr.end());
        int n = arr.size() / 20;
        for(int i = n; i < arr.size()-n; i++) {
            ans += arr[i];
        }
        return (double) ans / (arr.size()-2*n);
    }
};
// @lc code=end

