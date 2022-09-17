/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode*> mydfs(int l, int r) {
        vector<TreeNode*> v;
        if(l > r) {
            return vector<TreeNode*>{nullptr};
        }
        for (int ii = l; ii <= r; ii++) {
            vector<TreeNode*> Lnodes = mydfs(l, ii-1);
            vector<TreeNode*> Rnodes = mydfs(ii+1, r);
            for (int i = 0; i < Lnodes.size(); i++) {
                for (int j = 0; j < Rnodes.size(); j++) {
                    TreeNode* root = new TreeNode(ii);
                    root->left = Lnodes[i];
                    root->right = Rnodes[j];
                    v.push_back(root);
                }
            }
        }
        return v;
    }
    vector<TreeNode*> generateTrees(int n) {
        return mydfs(1, n);
    }
};
// @lc code=end

