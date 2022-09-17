/*
 * @lc app=leetcode.cn id=1403 lang=cpp
 *
 * [1403] 非递增顺序的最小子序列
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0, curr = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];
        sum = (sum + 2) / 2; // 向上取整
        for (int i = 0; i < nums.size(); i++) {
            if(curr >= sum)
                break;
            ans.push_back(nums[i]);
            curr += nums[i];
        }
        return ans;
    }
};
// @lc code=end
