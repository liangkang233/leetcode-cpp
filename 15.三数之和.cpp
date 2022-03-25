/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

// @lc code=start
// 双指针，排序后 遍历 确定第一个字符， 剩下的两个指针在双指针遍历
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2 && nums[i] <= 0; i++) {
            int start = i+1, stop = nums.size()-1, target = -nums[i];
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            while (start < stop) {  //需要对答案去重 即下面双指针的推进步长 和首字符长都不一定
                if(nums[start] + nums[stop] < target)
                    start++;
                else if(nums[start] + nums[stop] > target)
                    stop--;
                else {
                    ans.push_back(vector<int>{-target, nums[start], nums[stop]});
                    do {
                        stop--;
                    } while (stop > start && nums[stop] == nums[stop+1]); // 加start<stop 防止越界<0 或超size()
                    do {
                        start++;
                    } while (start < stop && nums[start] == nums[start-1]);                    
                }
            }
        }
        return ans;
    }
};
// @lc code=end
// [0,0,0,0,0,0,0,0,0]\n
// [-2,-2,1,1,1,1]\n
// [1,2,-2,-1]\n