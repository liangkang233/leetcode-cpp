/*
 * @lc app=leetcode.cn id=1636 lang=cpp
 *
 * [1636] 按照频率将数组升序排序
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) 
            mp[nums[i]]++;
        auto mycmp = [&mp](const int& x, const int& y) {
            if(mp[x] == mp[y])
                return x > y;
            return mp[x] < mp[y];
        };
        sort(nums.begin(), nums.end(), mycmp);
        return nums;
    }
};
// @lc code=end

