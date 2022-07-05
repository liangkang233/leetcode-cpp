/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的 k-diff 数对
 */

#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
// 使用哈希 set 即可
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        unordered_set<int> st, st1; // st记录所有元素 st1记录作过数对的元素较大值
        for(int i = 0; i < nums.size(); i++) {
            if(st1.find(nums[i]) == st1.end() && st.find(nums[i] - k) != st.end()) {
                ans++;
                st1.insert(nums[i]);
            }
            if(st1.find(nums[i] + k) == st1.end() && st.find(nums[i] + k) != st.end()) {
                ans++;
                st1.insert(nums[i] + k);
            }
            st.insert(nums[i]);
        }
        return ans;
    }
};
// @lc code=end

