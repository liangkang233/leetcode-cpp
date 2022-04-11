/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans = 0, maxn = 0; // 当前最长递增序列个数 当前递增序列最大长度
        vector<pair<int, int>> dp(nums.size(), make_pair(1, 1)); 
        // dp[i] 为 以i为起点(一定包含i)到达尾部的最大递增子序列长度 first 以及其个数 second
        for (int i = nums.size()-1; i >= 0; i--) {
            for (int j = i+1; j < nums.size(); j++) {
                if(nums[i] < nums[j]) {
                    if(1 + dp[j].first > dp[i].first) {
                        dp[i].first = dp[j].first + 1;
                        dp[i].second = dp[j].second;
                    }
                    else if(1 + dp[j].first == dp[i].first)
                        dp[i].second += dp[j].second;
                }
            }
            if(dp[i].first > maxn)
                ans = dp[i].second;
            else if(dp[i].first == maxn)
                ans += dp[i].second;
            maxn = max(dp[i].first, maxn);
        }
        return ans;
    }
};
// @lc code=end

// [10, 9, 2, 5, 3, 7, 101, 18]\n
// [2,1,100,101,102,10000,99,100]\n
// [100,101,102,10000,99,100,2,1100,101,102,1200,100,101,1202,102000,99,100,2,110,101,102,120,100,101,102,10,992,100,101,102,10,99,100,2,1100,101,102,10000,99,100,2,1,100,101,102,10000,99,100,2,99,100,2,1,100,101,102,10000,99,100,2,1,100,101,102,10000,99,100,2,1,100,101,102,10000,99,100,2,1,1234,546,8,9,435,856,83,46,87457,8,46,58237,65098,5,43,7,8,32]\n


// 官方的动态规划 跟自己写的差不多 不过dp[i]维护的是 从0到下标i(一定包含i)的最长递增序列
class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        int n = nums.size(), maxLen = 0, ans = 0;
        vector<int> dp(n), cnt(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j]; // 重置计数
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                ans = cnt[i]; // 重置计数
            } else if (dp[i] == maxLen) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};


// 官方的 贪心 前缀和 二分   绝了
class Solution {
    int binarySearch(int n, function<bool(int)> f) {
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (f(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

public:
    int findNumberOfLIS(vector<int> &nums) {
        vector<vector<int>> d, cnt; 
        // d[i][j] 表示为长度为 i 的递增序列的末尾值 其长度对应为cnt[i][j] 使用二维二分查找
        // 由300题目可知 该d[i]的数组广义递增, 原来的替换序列Maxnums操作 改为push到i长度的dp[i]
        for (int num : nums) {
            int i = binarySearch(d.size(), [&](int i) { return d[i].back() >= num; }); 
            // upper_bound 二分查找该 dp[i]最大值back 的第一个 元素大于 num 的下标 i
            int c = 1; // 临时计数值
            if (i > 0) {
                // lowerbound 在 dp[i-1] 中所有元素都是长度为i-1的 二分查找该序列中第一个大于等于num的序列
                int k = binarySearch(d[i - 1].size(), [&](int k) { return d[i - 1][k] < num; });
                c = cnt[i - 1].back() - cnt[i - 1][k]; // 只有这些序列 个数才会加一(即300题中这些元素会被替换的可能)
            }
            if (i == d.size()) { // 该下标超出 当前序列最大值 所以最大长度i+1 即d push新的元素
                d.push_back({num});
                cnt.push_back({0, c}); // 多push一个0 是为了上面c的第一次计算
            } else { // 300题目是对该元素进行替换 此处只是做push新的该长度序列尾部
                d[i].push_back(num);
                cnt[i].push_back(cnt[i].back() + c);
            }
        }
        return cnt.back().back();
    }
};