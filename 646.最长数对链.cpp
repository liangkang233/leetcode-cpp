/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// @lc code=start
// 注意题中没说明 链在原pairs中必须连续
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int ans = 0;
        sort(pairs.begin(), pairs.end()); //先按照首元素大小排序 确保遍历顺序正确
        vector<int> dp(pairs.size(), 1);
        for (int i = 0; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if(pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], dp[j] + 1);
            }            
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

// [[1,2],[2,3],[3,4],[1,2],[2,3],[33,44],[34,243],[2,3],[3,43]]
// [[1,2],[7,8],[4,5]]
