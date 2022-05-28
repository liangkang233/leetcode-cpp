/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<int> pre;
public:
    Solution(vector<int>& w) {
        pre = w;
        for (int i = 1; i < w.size(); i++)
            pre[i] += pre[i-1];
    }
    
    int pickIndex() {
        // 由题意 按照权重随机分配 即为 下标按照 前缀和分配
        int index = rand() % pre.back();
        return distance(pre.begin(), upper_bound(pre.begin(), pre.end(), index));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

