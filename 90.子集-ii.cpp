/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 题解说明有些瑕疵，数组排序后应该是想添加当前这个数时，上一个数未添加且与添加数相同才能跳过该递归
/* 去重方法：在递归时，若发现没有选择上一个数，
 且当前数字与上一个数相同想添加这个数时，
 则可以推断跳过当前生成的子集。
 以取三个相同值做例子 用二叉树true false代表是否取到 :
              /true
        /true/
  /true/     \false
 /     \       /true (无效)
/       \false/
\             \false
 \                    /(无效)
  \       /true(无效)/
   \false/           \(无效)
         \       /true(无效)
          \false/
                \false
 妙啊 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    void mydfs(vector<int>& nums, vector<int>& temp, int index, bool flag) { // flag true表示上一次递归填入了字符
        if(index >= nums.size()) {
            ans.push_back(temp);
            return;
        }
        mydfs(nums, temp, index+1, false);
        if( flag || nums[index-1]!=nums[index]) {
            temp.push_back(nums[index]);
            mydfs(nums, temp, index+1, true);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        mydfs(nums, temp, 0, true);
        return ans;
    }
};
// @lc code=end
// [1,-8,-4,0,0,0,4,4,2,2]\n
// [1,2,2,2]\n
// [1]\n

