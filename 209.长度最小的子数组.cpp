/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 初始子数组为整个数组 从首确定head子数组头 tail滑动到尾
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, sum = 0, tail = 0;
        for (int head = 0; head < nums.size(); head++) {
            while (sum < target && tail < nums.size()) {
                sum += nums[tail];
                tail++;
            }
            if(sum >= target) // 该区间有效
                ans = min(ans, tail - head);
            sum -= nums[head]; //减去该滑动窗口头
        }
        // 官方的滑动
        // int head = 0;
        // while (tail < nums.size()) {
        //     sum += nums[tail];
        //     while (sum >= target) {
        //         ans = min(ans, tail - head + 1);
        //         sum -= nums[head];
        //         head++;
        //     }
        //     tail++;
        // }
        return ans==INT_MAX ? 0 : ans;
    }
};
// @lc code=end


// 二刷滑动窗口 时间复杂度O(n) 空间O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, temp = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            temp += nums[i];
            if(temp >= target) {
                while (j <= i && temp >= target) {
                    ans = min(ans, i-j+1);
                    temp-=nums[j];
                    j++;
                }
            }
        }
        return ans==INT_MAX ? 0 : ans ;
    }
};


// 官方的 前缀和 + 二分查找   时间复杂度 O(n*logn) 空间O(1) 都不如滑动窗口
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0); 
        // 为了方便计算，令 size = n + 1 
        // sums[0] = 0 意味着前 0 个元素的前缀和为 0
        // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
        // 以此类推
        for (int i = 1; i <= n; i++)
            sums[i] = sums[i - 1] + nums[i - 1];
        for (int i = 1; i <= n; i++) {
            int target = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), target);
            if (bound != sums.end())
                ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// 10\n[1]\n
// 1\n[10]\n
// 1\n[1,10]\n
// 7\n[2,3,1,2,4,3]\n
// 697439\n[5334,6299,4199,9663,8945,3566,9509,3124,6026,6250,7475,5420,9201,9501,38,5897,4411,6638,9845,161,9563,8854,3731,5564,5331,4294,3275,1972,1521,2377,3701,6462,6778,187,9778,758,550,7510,6225,8691,3666,4622,9722,8011,7247,575,5431,4777,4032,8682,5888,8047,3562,9462,6501,7855,505,4675,6973,493,1374,3227,1244,7364,2298,3244,8627,5102,6375,8653,1820,3857,7195,7830,4461,7821,5037,2918,4279,2791,1500,9858,6915,5156,970,1471,5296,1688,578,7266,4182,1430,4985,5730,7941,3880,607,8776,1348,2974,1094,6733,5177,4975,5421,8190,8255,9112,8651,2797,335,8677,3754,893,1818,8479,5875,1695,8295,7993,7037,8546,7906,4102,7279,1407,2462,4425,2148,2925,3903,5447,5893,3534,3663,8307,8679,8474,1202,3474,2961,1149,7451,4279,7875,5692,6186,8109,7763,7798,2250,2969,7974,9781,7741,4914,5446,1861,8914,2544,5683,8952,6745,4870,1848,7887,6448,7873,128,3281,794,1965,7036,8094,1211,9450,6981,4244,2418,8610,8681,2402,2904,7712,3252,5029,3004,5526,6965,8866,2764,600,631,9075,2631,3411,2737,2328,652,494,6556,9391,4517,8934,8892,4561,9331,1386,4636,9627,5435,9272,110,413,9706,5470,5008,1706,7045,9648,7505,6968,7509,3120,7869,6776,6434,7994,5441,288,492,1617,3274,7019,5575,6664,6056,7069,1996,9581,3103,9266,2554,7471,4251,4320,4749,649,2617,3018,4332,415,2243,1924,69,5902,3602,2925,6542,345,4657,903]\n

// 二刷
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int temp = 0, ans = INT_MAX;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            temp += nums[i];
            while (temp >= target) {
                ans = min(ans, i - j + 1);
                temp -= nums[j++];
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};
