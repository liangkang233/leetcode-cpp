/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
 */

#include <vector>
#include <iostream>
#include <string>
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
    int depth = 0;
public:
    void mydfs(TreeNode* root, int dep) {
        if(!root) return;
        depth = max(dep, depth);
        mydfs(root->left, dep+1);
        mydfs(root->right, dep+1);
    }
    void mydfs1(TreeNode* root, vector<vector<string>>& ans, int l, int r, int dep) {
        if(!root) return;
        int mid = (r - l ) / 2 + l;
        ans[dep][mid] = to_string(root->val);
        mydfs1(root->left, ans, l, mid-1, dep+1);
        mydfs1(root->right, ans, mid+1, r, dep+1);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        mydfs(root, 1);
        int r = pow(2, depth) - 2, l = 0;
        vector<vector<string>> ans(depth, vector<string>(r+1, ""));
        mydfs1(root, ans, l, r, 0);
        return ans;
    }
};
// @lc code=end