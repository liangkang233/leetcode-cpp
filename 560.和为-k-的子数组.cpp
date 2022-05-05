/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// prefix 前缀
// suffix 后缀

// 子数组要求连续 并且包含自身
// nums[i] 包含0 边界处理很棘手 且有正有负 说明滑动窗口不可行

// 记录所有的前缀和, 区间之和为k 即 prefix 之差为k
// 采用map 查询前缀数组值的方式降低时间复杂度
// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> pre_map;
        int prefix = 0, ans = 0;
        pre_map.insert(make_pair(0, 1));        // first 为前缀和 second 为相应个数
        for (int i = 0; i < nums.size(); i++) { // 由于从左向右遍历 map统计个数只有其左子数组
            prefix += nums[i];
            if(pre_map.find(prefix - k) != pre_map.end())
                ans += pre_map[prefix - k];
            pre_map[prefix]++;
            //pre_map没有元素 使用[]访问时会自动初始化为0
        }
        return ans;
    }
};
// @lc code=end
// [1, 1, 1]\n2
// [0,1,0,0,3,0,0,0,1]\n3
// [3, 3, 0, 0, 2, 1, 2, 2, 1]\n3



// 暴力法显然超时 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start) {
            int sum = 0;
            for (int end = start; end >= 0; --end) {
                sum += nums[end];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};

// 二刷还是没掌握精髓 前缀和不需要用一个数组维护
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++)
            prefix[i+1] = prefix[i] + nums[i];
        unordered_map<int, int> mymap;  // key 为数据  value为对应 出现次数
        mymap[0] = 1;
        for (int i = 0; i < n; i++) {
            ans += mymap[prefix[i+1] - k];
            mymap[prefix[i+1]]++;
        }
        return ans;
    }
};
