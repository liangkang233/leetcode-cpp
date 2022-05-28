/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k == 0 || nums.size() < 2)
            return false;
        set<int> myset;
        int index = 0;
        k++; // 这也坑我 下标数之差可以等于k 说明个数为k+1个
        for (; index < nums.size() && index < k; index++) { // 先填充k个元素
            if(myset.find(nums[index]) != myset.end())
                return true;
            auto it = myset.insert(nums[index]).first, L = it, R = it;
            --L; ++R;
            if((it!=myset.begin() && (long long)*it-*L<=t) || (R!=myset.end() && (long long)*R-*it<= t))
                return true;
        }
        for (; index < nums.size(); index++) {
            myset.erase(nums[index-k]);
            if(myset.find(nums[index]) != myset.end())
                return true;
            auto it = myset.insert(nums[index]).first, L = it, R = it;
            --L; ++R;
            if((it!=myset.begin() && (long long)*it-*L<=t) || (R!=myset.end() && (long long)*R-*it<= t))
                return true;
        }
        return false;
    }
};
// @lc code=end
// [1,2]\n1\n2
// [1,5,9,1,5,9]\n2\n3
// [1,5,9,123,45,890,567,35,236,78,92,3]\n5\n1
// [1,2,3,1]\n3\n0
// [-2147483648,2147483647]\n1\n1