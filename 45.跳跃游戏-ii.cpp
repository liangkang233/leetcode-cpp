/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 类似55题的贪心
    int jump(vector<int>& nums) {
        int ans = 0, maxn = nums[0], last = 0;  //last表示为上一个的落脚点
        for (int i = 0; i < nums.size() - 1; i++) { //题中说明必定可以到达终点
            maxn = max(i+nums[i], maxn);
            if (maxn >= nums.size() - 1)
                return ans + 1;            
            if (i == last) {
                last = maxn;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

