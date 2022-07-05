// https://www.nowcoder.com/practice/4892d3ff304a4880b7a89ba01f48daf9?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;


// 两次交易 切割为两个数组 即计算 0-i i-size 两区间的最大赚取数据
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 两次交易所能获得的最大收益
     * @param prices int整型vector 股票每一天的价格
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), 0), dp1(dp);
        int t = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if(prices[i] - t > dp[i-1]) {
                dp[i] = prices[i] - t;
            } else {
                dp[i] = dp[i-1];
            }
            t = min(t, prices[i]);
        } t = prices.back();
        for (int i = prices.size() - 2; i >= 0; i--) {
            if(t - prices[i] > dp1[i+1]) {
                dp1[i] = t - prices[i];
            } else {
                dp1[i] = dp1[i+1];
            }
            t = max(t, prices[i]);
        }
        int ans = 0;
        for (int i = 0; i < prices.size(); i++)
            ans = max(ans, dp[i] + dp1[i]);
        return ans;
    }
};