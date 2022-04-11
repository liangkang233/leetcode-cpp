/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> mynums;
public:
    Solution(vector<int>& nums) {
        mynums.resize(nums.size());
        copy(nums.begin(), nums.end(), mynums.begin());
    }
    
    vector<int> reset() {
        return mynums;
    }
    
    vector<int> shuffle() {
        vector<int> temp(mynums);
        int n = mynums.size();
        for (int i = 0; i < n; i++) {
            // 挑出随机数放到未确定元素的最后一个 减少一个 未确定元素后再迭代进行
            swap(temp[n-1-i], temp[rand() % (n-i)]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
// ["Solution","reset","shuffle","reset","shuffle"]\n[[[-6,10,184]],[],[],[],[]]\n