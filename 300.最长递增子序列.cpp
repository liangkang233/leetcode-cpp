/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
// 考虑一个简单的贪心，如果我们要使上升子序列尽可能的长，
// 则我们需要让序列上升得尽可能慢，因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
// 即遍历 nums 将nums[i] 替换为第一个大于等于 该值的元素， 如果没有 push 该元素 增长序列
// 遍历构建最长字串，二分查找并修改该串数据 时间复杂度 O(n*longn)

// 以输入序列 [0, 8, 4, 12, 2]为例：
// 第一步插入 0，d = [0]；
// 第二步插入 8，d = [0, 8]；
// 第三步插入 4，d = [0, 4]]；
// 第四步插入 12，d = [0, 4, 12]；
// 第五步插入 2，d = [0, 2, 12]。

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> Maxnums{nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] > Maxnums.back())
                Maxnums.push_back(nums[i]);
            else {
                auto index = lower_bound(Maxnums.begin(), Maxnums.end(), nums[i]);
                *index = nums[i];
            }
        }
        return Maxnums.size();
    }
};
// @lc code=end
// [1]\n
// [100,101,102,10000,99,100,2,1100,101,102,1200,100,101,1202,1020,99,100,2,110,101,102,120,100,101,102,10,992,100,101,102,10,99,100,2,1100,101,102,10000,99,100,2,1,100,101,102,10000,99,100,2,99,100,2,1,100,101,102,10000,99,100,2,1,100,101,102,378,99,100,2,1,100,101,102,123,99,100,2,1,1234,546,8,9,435,856,83,46,12,8,46,12,435,5,43,7,8,32]\n

// 动态规划 时间复杂度 O(n*n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1, maxn = 1;
        // dp[i] 为 以i为起点(一定包含i)到达尾部的最大递增子序列长度
        vector<int> dp(nums.size(), 1);
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i+1; j < nums.size(); j++) {
                if(nums[i] < nums[j])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            ans = max(dp[i], ans);
        }
        return ans;        
    }
};