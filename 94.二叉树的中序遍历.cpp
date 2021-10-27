/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> print;
    void myprint(TreeNode* tree) {
        if(tree == nullptr)
            return ;
        myprint(tree->left);
        print.push_back(tree->val);
        myprint(tree->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        myprint(root);     
        return print;
    }
};
// @lc code=end

