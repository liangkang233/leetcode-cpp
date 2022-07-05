/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        int dep = 0;
        queue<TreeNode*> myque;
        if(root)
            myque.push(root);
        while (!myque.empty()) {
            int size = myque.size();
            for (int i = 0; i < size; i++) {
                TreeNode* t = myque.front();
                myque.pop();
                if(t->left)
                    myque.push(t->left);
                if(t->right)
                    myque.push(t->right);
            }
            dep++;
        }
        return dep;
    }
};
// @lc code=end

