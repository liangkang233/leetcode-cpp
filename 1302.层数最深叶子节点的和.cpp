/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
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
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> que;
        if(root) que.push(root);
        while (!que.empty()) {
            int size = que.size(), sum = 0;
            while (size--) {
                TreeNode* now = que.front();
                que.pop();
                sum += now->val;
                if(now->left) que.push(now->left);
                if(now->right) que.push(now->right);
            }
            ans = sum;
        }
        return ans;
    }
};
// @lc code=end

