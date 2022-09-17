/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
// 翻译题意 求奇偶数差值
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd = 0, even = 0;
        for (int i = 0; i < position.size(); i++) {
            if(position[i] % 2 == 0)
                even++;
            else 
                odd++;
        }
        return min(odd, even);
    }
};
// @lc code=end

// [1,1000000000]\n[1,2,3]\n[2,2,2,3,3]\n