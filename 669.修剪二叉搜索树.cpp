/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root) {
            if(root->val < low) {
                return trimBST(root->right, low, high);
            } else if(root->val > high) {
                return trimBST(root->left, low, high);
            } else {
                root->left = trimBST(root->left, low, high);
                root->right = trimBST(root->right, low, high);
            }
        }
        return root;
    }
};
// @lc code=end
// [3,0,4,null,2,null,null,1]\n1\n3\n