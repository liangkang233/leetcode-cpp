/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
private:
    TreeNode* fa;
    bool flag = false;
public:
    void mydfs(TreeNode* root, pair<TreeNode*, TreeNode*>& ms) {
        if(!root || flag) return;
        mydfs(root->left, ms);
        if(fa->val > root->val) {
            if(ms.first) {
                flag = true;
                swap(root->val, ms.first->val);
            } else {
                ms.first = fa;
                ms.second = root;
            }
        }
        fa = root;
        mydfs(root->right, ms);
    }
    void recoverTree(TreeNode* root) {
        TreeNode f = TreeNode(INT_MIN);
        fa = &f;
        pair<TreeNode*, TreeNode*> ms{nullptr, nullptr};
        mydfs(root, ms);
        if(!flag)
            swap(ms.first->val, ms.second->val);
    }
};
// @lc code=end
// [3,1,4,null,null,2]\n
   