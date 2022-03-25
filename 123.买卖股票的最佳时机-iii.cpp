/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    // 参考121, 交易次数为两次，就把整个数组划分为 0,i 与 i+1, size-1 两个区间的第一问
    // 注意 由于 i+1 到 size-1 是反向的 遍历时就不是找最大值相减 而是找最小值
    int maxProfit(vector<int>& prices) {
        int min1 = prices.front(), max2 = prices.back(), ans = 0;
        vector<int> deal1(prices.size(), 0), deal2(deal1); // deal1[i]为正序 i+1长度 的交易赚的最大值 daal2[i]为逆序 size-i 长度赚最大值
        for (int i = 1, j = prices.size() - 2; i < prices.size(); i++, j--) {
            if(prices[i] - min1 > deal1[i-1])
                deal1[i] = prices[i] - min1;
            else{
                min1 = min(prices[i], min1);
                deal1[i] = deal1[i-1];
            }
            if(max2 - prices[j] > deal2[j+1])
                deal2[j] = max2 - prices[j];
            else{
                max2 = max(prices[j], max2);
                deal2[j] = deal2[j+1];
            }
        }
        for (int i = 0; i < deal1.size()-1; i++) // 分为 i+1 个 和后缀 size-i-1 个
            ans = max(ans, deal1[i] + deal2[i+1]);
        return max(ans, deal1.back());  // 有可能不分区 是最大值 例如纯递增
    }
};
// @lc code=end
// [1,4,2]\n
// [1,2,3]\n
// [1,2,3,4,5,11,23,45,56,1234,234,545,234,43,21,435,532]\n
// [7,6,5,3,1]\n
// [1,2,4,2,5,7,2,4,9,0]\n


    // 这种做法不是最优解, 例如 [1,2,4,2,5,7,2,4,9,0] 应该是 1-7 2-9  而不是下面输出的2-7 2-0
    int maxProfit(vector<int>& prices) {
        int temp = 0;
        bool flag = false;
        vector<int> t{0, 0};
        priority_queue<int, vector<int>, greater<int>> deal(t.begin() , t.end());
        for (int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1])
                temp += prices[i] - prices[i-1];
            else {
                flag = false;
                if(deal.top() < temp) {
                    deal.push(temp);
                    deal.pop();
                }
                temp = 0;
            }
            // cout << temp << endl;
        }
        if(deal.top() < temp) {
            deal.push(temp);
            deal.pop();
        }
        temp = deal.top();
        cout << temp << " " << endl;
        deal.pop();
        cout << deal.top() << " " << endl;
        return temp + deal.top();
    }
