/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
 */

#include<iostream>
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
private:
    TreeNode* head;
public:
    void mydfs(TreeNode* root) {
        if(root) {
            mydfs(root->left);
            // cout << root->val << endl;
            head->right = new TreeNode(root->val);
            head = head->right;
            mydfs(root->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode ans = TreeNode(-1);
        head = &ans;
        mydfs(root);
        return ans.right;
    }
};
// @lc code=end

// 官方解 不需要额外空间
class Solution {
private:
    TreeNode *resNode;
public:
    // 在中序遍历的过程中修改节点指向
    void inorder(TreeNode *node) {
        if (node) {
            inorder(node->left);
            resNode->right = node;
            node->left = nullptr;
            resNode = node;
            inorder(node->right);
        }
    }

    TreeNode *increasingBST(TreeNode *root) {
        TreeNode dummyNode = TreeNode(-1);
        resNode = &dummyNode;
        inorder(root);
        return dummyNode.right;
    }
};