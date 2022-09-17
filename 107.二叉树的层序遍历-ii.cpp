/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        if(root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> t;
            for (int i = 0; i < size; i++) {
                TreeNode* h = que.front();
                t.push_back(h->val);
                que.pop();
                if(h->left) que.push(h->left);
                if(h->right) que.push(h->right);
            }
            ans.push_back(t);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

