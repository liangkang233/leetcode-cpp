/*
 * @lc app=leetcode.cn id=1608 lang=cpp
 *
 * [1608] 特殊数组的特征值
 */

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = nums.size(), i = 0;
        while (i < nums.size()) {
            if(nums[i] >= ans)
                break;
            i++, ans--;
        }
        if(i > 0 && nums[i-1] >= ans) // 防止 类似 0 2 3 4 4 结果
            return -1;
        return nums.size()-i == ans ? ans : -1;
    }
};
// @lc code=end
// [3,5]\n[0,4,3,0,4]\n[3,6,7,7,0]\n


// 正确写法
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] >= i && (i == n || nums[i] < i)) {
                return i;
            }
        }
        return -1;
    }
};
