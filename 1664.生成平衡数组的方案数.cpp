/*
 * @lc app=leetcode.cn id=1664 lang=cpp
 *
 * [1664] 生成平衡数组的方案数
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int ans = 0, len = nums.size();
        vector<int> record(len+1, 0);//record[n]表示nums前n个数字中奇数减去偶数的值
        for (int i = 0; i < len; i++) {
            int temp = i&1 ? -nums[i] : nums[i];// i&1 => i%2
            record[i+1] = record[i] + temp ;
        }
        for (int i = 0; i < len; i++) { 
            // 遍历测试删除i位是否为平衡数组，删减nums[i]后，前有i个应为record[i]
            // 删减后，后段奇偶变化 为(record[len]-record[i+1])*-1
            if(record[i] - record[len] + record[i+1] == 0)
                ans ++;
        }
        return ans;
    }
};
// @lc code=end

