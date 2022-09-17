/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

#include <vector>
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// @lc code=start
class Solution {
public:
    TreeNode* mydfs(const vector<int>& nums, int l, int r) {
        if(l > r) 
            return nullptr;
        int index = l;
        for (int i = l+1, maxi = nums[l]; i <= r; i++) {
            if(nums[i] > maxi) {
                index = i;
                maxi = nums[i];
            }
        }
        return new TreeNode(nums[index], mydfs(nums, l, index-1), mydfs(nums, index+1, r));
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return mydfs(nums, 0, nums.size()-1);
    }
};
// @lc code=end
