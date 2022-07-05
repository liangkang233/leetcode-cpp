/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include<iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int last = 1, now = 1;
        for (int i = 1; i < n; i++) {
            int temp = now;
            now += last;
            last = temp;
        }
        return now;
    }
};
// @lc code=end

