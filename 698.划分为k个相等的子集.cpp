/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 直接递归会超时, 使用状态dp来做 秒啊
// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        if(sum % k != 0 || nums.back() > sum / k) return false;
        // 如果集合里所有元素的和，模（mod） target 加上当前考虑的一个数 num 以后的和小于等于每个划分的平均数 target，
        // 那么这个子集有可能是满足题意的一个或者多个划分，否则就一定不是满足题意的一个或者多个划分。
        int size = 1 << len, N = sum/k; // 一共 size 状态    每个桶为最多装N
        vector<int> dp_sum(size, -1); // 对应该状态 所有元素和  -1表示一定不存在
        dp_sum[0] = 0;
        for (int i = 0; i < size; i++) {
            if(dp_sum[i] < 0) continue; // 该状态无效 跳过
            // 基于当前状态，添加nums的j下标
            for (int j = 0; j < len; j++) {
                if ((i & (1 << j)) != 0) continue;  // 无效下标
                int newi = i | (1<<j);              // 添加该下标后的新状态
                if(dp_sum[newi] >= 0) continue;     // 新状态之前计算过可达 无需重复计算
                if(dp_sum[i] % N + nums[j] <= N) {
                    dp_sum[newi] = dp_sum[i] + nums[j];
                } else {
                    break;
                }
            }
        }
        return dp_sum.back() >= 0;
    }
};
// @lc code=end

class Solution {
public:
    bool mydfs(vector<int>& nums, vector<int>& t, int index, int N) {
        if(index == nums.size())
            return true;
        for(int j = 0; j < t.size(); j++) {
            if(t[j] + nums[index] <= N) {
                t[j] += nums[index];
                if(mydfs(nums, t, index+1, N))
                    return true;
                t[j] -= nums[index];
            } else {
                break;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        if(sum % k != 0 || nums.back() > sum / k) {
            // cout << "false" << endl;
            return false;
        } else {
            vector<int> t(k, 0);
            if(mydfs(nums, t, 0, sum / k)) {
                return true;
            } else {
                return false;
            }
        }
    }
};