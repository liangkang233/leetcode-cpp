/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
 */

#include <queue>
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int count = INT_MIN, now = 1, ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size(), sum = 0;
            while (size--) {
                TreeNode* curr = que.front();
                que.pop();
                sum += curr->val;
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            if(sum > count) {
                ans = now;
                count = sum;
            }
            now++;
        }
        return ans;
    }
};
// @lc code=end

