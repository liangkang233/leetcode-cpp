/*
 * @lc app=leetcode.cn id=1953 lang=cpp
 *
 * [1953] 你可以工作的最大周数
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long ans = 0;
        int max = 0;
        // if (n==1) return 1;
        for (int i = 0; i < milestones.size(); i++) {
            ans += milestones[i];
            if (milestones[i] > max)
                max = milestones[i]; 
        }
        if ((ans-max)*2 + 1 < ans) //补偿超出所有和的范围
        // if ( ans-max+1 < max) //等价官方判定式
            return (ans-max)*2 + 1;
        return ans;
    }
};
