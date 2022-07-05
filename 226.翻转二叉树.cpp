/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

#include <iostream>
#include <stack>
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
    TreeNode* invertTree(TreeNode* root) {
        if(root) {
            TreeNode* l = root->left, *r = root->right;
            root->left = invertTree(r);
            root->right = invertTree(l);
        }
        return root;
    }
};
// @lc code=end

// [1,2,3,4,5,6,7,8,9,0,9,8,78,7,6,56,5,4,3,3,2,22,1,3,4,4,5,6,6,7]\n