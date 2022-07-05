/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */

#include <algorithm>
#include <vector>
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
// 进阶题 124.二叉树中的最大路径和.cpp
class Solution {
private:
    int ans = 1;
public:
    int mydfs(TreeNode* root) { // 返回最大一支树长度
        if(!root) return 0;
        int l = mydfs(root->left);
        int r = mydfs(root->right);
        ans = max(l + r + 1, ans);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        mydfs(root);
        return ans - 1;
    }
};
// @lc code=end

