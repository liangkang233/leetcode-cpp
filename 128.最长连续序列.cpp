/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

#include <iostream>
#include <unordered_set>
using namespace std;


// @lc code=start
// 直接用set 时间复杂度为 O(nlgn)
// 换个思路 不必要从 i 统计 进行遍历 而是从 set存在元素进行遍历统计
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0, now;
        unordered_set<int> ms(nums.begin(), nums.end());
        for (const int& i : ms) {
            if(ms.find(i-1) == ms.end()) { // 该数据必定为 数组头
                now = i+1;
                while (ms.find(now) != ms.end()) now++;
                ans = max(ans, now - i);
            }
        }
        return ans;
    }
};
// @lc code=end
// [100, 99,100,-102,-101]\n
