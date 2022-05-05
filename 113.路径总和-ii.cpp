/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// Definition for a binary tree node.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    vector<vector<int>> ans;
    void mydfs(TreeNode* now, vector<int>& path, int cost) {
        if(cost == 0 && !now->left && !now->right)
            ans.push_back(path);
        else {
            if(now->left) {
                cost -= now->left->val;
                path.push_back(now->left->val);
                mydfs(now->left, path, cost);
                path.pop_back();
                cost += now->left->val;
            }
            if(now->right) {
                cost -= now->right->val;
                path.push_back(now->right->val);
                mydfs(now->right, path, cost);
                path.pop_back();
                cost += now->right->val;
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root) {
            vector<int> path{root->val};
            mydfs(root, path, targetSum - root->val);
        }
        return ans;
    }
};
// @lc code=end
// []\n0
// [0,1,2,2,-1,0,2,-2]\n0
// [1,2,3]\n0

