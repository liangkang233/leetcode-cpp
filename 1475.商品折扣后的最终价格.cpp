/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 *
 * [1475] 商品折扣后的最终价格
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices);
        for(int i = 0; i < prices.size(); i++) {
            for (int j = i+1; j < prices.size(); j++) {
                if(prices[j] <= prices[i]) {
                    ans[i] -= prices[j];
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

