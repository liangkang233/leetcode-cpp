/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
 */
#include <iostream>
#include <algorithm>
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
    int Val, Depth;
    void find(TreeNode* tree, int d) {
        // cout << tree->val << ",d= " << d << endl;
        if(d == Depth-1) {
            tree->left = new TreeNode(Val, tree->left, nullptr);
            tree->right = new TreeNode(Val, nullptr, tree->right);
            return;
        }
        if (tree->left != nullptr)
            find(tree->left, d+1);
        if (tree->right != nullptr)
            find(tree->right, d+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // 使用dfs确定所有层数为depth的树，由题意添加子树默认都添加为左子树
        // 注意 按照题目要求去找depth-1行并修改 否则将会改变子树左右顺序关系 Solution2时错误的
        Val = val, Depth = depth;
        if(depth <= 1)
            return new TreeNode(val, root, nullptr);
        find(root, 1);
        return root;
    }
};
// @lc code=end

// 有问题
class Solution2 {
public:
    int Val, Depth;
    void find(TreeNode* tree, int d) {
        cout << tree->val << ",d= " << d << endl;
        if(d == Depth) {
            tree->left = new TreeNode(tree->val, tree->left, tree->right);
            tree->right = nullptr;
            tree->val = Val;
            return;
        }
        if(tree->left != nullptr)
            find(tree->left, d+1);
        if(tree->right != nullptr)
            find(tree->right, d+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        Val = val, Depth = depth;
        find(root, 1);
        return root;
    }
};

// 二刷
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth <= 1) return new TreeNode(val, root, nullptr);
        depth--;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty() && depth) {
            int size = que.size();
            --depth;
            for(int i = 0; i < size; i++) {
                TreeNode* curr = que.front();
                que.pop();
                if(!depth) {
                    curr->left = new TreeNode(val, curr->left, nullptr);
                    curr->right = new TreeNode(val, nullptr, curr->right);
                } else {
                    if(curr->left) que.push(curr->left);
                    if(curr->right) que.push(curr->right);
                }
            }
        }
        return root;
    }
};