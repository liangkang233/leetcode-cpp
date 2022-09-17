/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 */

#include <iostream>
#include <algorithm>
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


// 题目中求的是两点之间相同的节点边数

// @lc code=start
class Solution {
private:
    int ans = 0; 
public:
    int mydfs(TreeNode* node) { // mydfs 返回 等于当前val的最大边长
        if(!node) return 0;
        int L = mydfs(node->left), R = mydfs(node->right);
        if(node->left && node->left->val == node->val) 
            L++; // 如果有相等节点 左枝加上当前节点
        else 
            L = 0;
        if(node->right && node->right->val == node->val) 
            R++; // 如果有相等节点 右枝加上当前节点
        else 
            R = 0;
        ans = max(ans, L+R);
        // cout << node->val << " " << L << " " << R << endl;
        return max(L, R);
    }
    int longestUnivaluePath(TreeNode* root) {
        mydfs(root);
        return ans;
    }
};
// @lc code=end
// [1,null,1,1,1,1,1,1]\n


// 双重递归 会超时 为什么会写成这样。。。
class Solution {
private:
    int ans = 0; 
public:
    int mydfs(TreeNode* node, int val) {
        if(!node) return 0;
        int L = mydfs(node->left, val), R = mydfs(node->right, val);
        int now_L = node->val == val ? L : mydfs(node->left, node->val);
        int now_R = node->val == val ? R : mydfs(node->right, node->val);
        ans = max(ans, now_L + now_R);
        if(node->val == val) {
            return 1 + max(L, R);
        } else {
            return 0;
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        mydfs(root, -1);
        return ans;
    }
};