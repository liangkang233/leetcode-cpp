/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1])
                ans += prices[i] - prices[i-1];
        }
        return ans;
    }
};
// @lc code=end

// [1,2,3,4,5]\n
// [7,6,4,3,1]\n