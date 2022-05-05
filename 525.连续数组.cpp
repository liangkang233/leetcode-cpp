/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// @lc code=start
// 与560题目类似
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0, n = nums.size(), prefix = 0;
        unordered_map<int, int> mymap; // key 为 1 与 0 数量的差值 value对应差值的最小下标
        mymap[0] = -1;
        for (int i = 0; i < n; i++) {
            prefix += nums[i] ? 1 : -1;  // 当前前缀的 1 0 数量差值
            if(mymap.find(prefix) != mymap.end())
                ans = max(i - mymap[prefix], ans);
            else
                mymap.insert(make_pair(prefix, i));
        }
        return ans;
    }
};
// @lc code=end

// [0,1,0]
// [0,0,1,0,0,0,1,1]
// [0,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,1,0,1,0,0,1,1,0,1,0,1,0,0]\n