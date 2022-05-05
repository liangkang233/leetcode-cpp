/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

// Definition for a binary tree node.
#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> myque;
        int n = 0, level = 1, MAX = INT_MIN;
        if(root)
            myque.push(root);
        while (!myque.empty()) {
            TreeNode* now = myque.front();
            myque.pop();
            if(now->left)
                myque.push(now->left);
            if(now->right)
                myque.push(now->right);
            n++;
            MAX = max(MAX, now->val);
            if(n == level) {
                n = 0;
                level = myque.size();
                ans.push_back(MAX);
                MAX = INT_MIN;
            }
        }
        return ans;
    }
};
// @lc code=end

