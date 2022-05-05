/*
 * @lc app=leetcode.cn id=1038 lang=cpp
 *
 * [1038] 从二叉搜索树到更大和树
 */

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
// 创建新树 前序创节点 中序添加值
class Solution {
private:
    int sum = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode* now = nullptr;
        if(root) {
            now = new TreeNode(root->val); // 先复制节点
            // 中序遍历即为 搜索树的正序顺序
            now->right = bstToGst(root->right);
            now->val += sum;
            sum = now->val;
            now->left = bstToGst(root->left);
        }
        return now;
    }
};
// @lc code=end
// []\n
// [0,null,1]