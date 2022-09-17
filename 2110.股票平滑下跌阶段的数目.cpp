/*
 * @lc app=leetcode.cn id=2110 lang=cpp
 *
 * [2110] 股票平滑下跌阶段的数目
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        vector<int> v(prices.size()+1, 0);
        int count = 1;
        for (int i = 1; i < prices.size(); i++) {
            if(prices[i] == prices[i-1]-1) {
                count++;
            } else {
                v[count]++;      
                count = 1;
            }
        } v[count]++;
        for (int i = 0; i < v.size(); i++){
            if(v[i] == 0) continue;
            // cout << i << " have " << v[i] << endl;
            ans += (long long)(1+i) * i / 2 * v[i];
        }
        return ans;
    }
};
// @lc code=end

