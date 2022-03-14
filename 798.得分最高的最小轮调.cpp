/*
 * @lc app=leetcode.cn id=798 lang=cpp
 *
 * [798] 得分最高的最小轮调
 */

#include <vector>
#include <iostream>
using namespace std;

// 设下标为i, 值为x，当值x小于等于下标i时 才计分 下面列举得分时 k 的取值范围
// 注意 x <= nums.size()-1
// i >= x时;    k >= i+1 或 k <= i-x
// i < x时;   i+1 <= k <= nums.size()-x+i
// 遍历数组, 将所有k能够成立的数记录对应下标的数组 即k在1-3 可以使这个i有效，则在k_num记录元素加1
// k_num 使用差分数组做记录 区间加的时间复杂度降为O(1)
// @lc code=start
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        vector<int> k_num(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if(i < nums[i]) {
                k_num[i+1]++;
                if(-nums[i]+i+1 <= -1)
                    k_num[nums.size()-nums[i]+i+1]--;
            }
            else {
                k_num[0]++;
                if(i+1 < nums.size())
                    k_num[i+1]++;
                if( i-nums[i]+1 < nums.size())
                    k_num[i-nums[i]+1]--;
            }
        }
        // 差分记录后统计值
        int bestIndex = 0, maxScore = 0, score = 0;
        for (int i = 0; i < k_num.size(); i++) {
            score += k_num[i];
            if (score > maxScore) {
                bestIndex = i;
                maxScore = score;
            }
        }
        return bestIndex;
    }
};
// @lc code=end

// [2,3,1,4,0]\n
// [1,3,0,2,4]\n
