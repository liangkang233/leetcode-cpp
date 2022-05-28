/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
// 请注意，顺序不同的序列被视作不同的组合。
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if(i-nums[j] >= 0 && (long long)dp[i] + dp[i-nums[j]] <= INT_MAX) // 排除越界值
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[target];
    }
};
// @lc code=end
// [3,7]\n5
// [14,56,77,89,90]\n368
// [10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111]\n999

// 这样只是 不同子数组 问题中不同顺序的子序列也要考虑为一种结果
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums[i]; j <= target; j++) {
                dp[j] += dp[j-nums[i]];
            }
            for (auto &&i : dp) {
                cout << i << " ";
            } cout << "\n";
        }
        return dp[target];
    }
};