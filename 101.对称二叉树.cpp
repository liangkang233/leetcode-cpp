/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

#include <iostream>
#include <queue>
using namespace std;
// 二叉树节点的定义。
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 完全二叉树规律，设当前节点为X。则子树节点为2X+1 2X+2，父节点为(X-1)/2。 
// 此处并非一定是完全二叉树

// @lc code=start
class Solution {
public:
    // 递归法
    bool Subtree(TreeNode* Lnode, TreeNode* Rnode) {
        if (Lnode == nullptr && Rnode == nullptr)
            return true;
        else if(Lnode == nullptr || Rnode == nullptr)
            return false;
        else {
            if (Lnode->val != Rnode->val)
                return false;            
            if (Subtree(Lnode->left, Rnode->right) && 
                Subtree(Lnode->right, Rnode->left))
                    return true;
            return false;            
        }
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)   return true; 
        return Subtree(root->left, root->right);
    }
};
// @lc code=end

// 官方迭代法   使用队列先进先出  bfs
class Solution1{
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode* n1, * n2;
        queue<TreeNode* > myqueue;
        myqueue.push(root->left);
        myqueue.push(root->right);
        while(!myqueue.empty()) {
            n1 = myqueue.front();   myqueue.pop();
            n2 = myqueue.front();   myqueue.pop();
            if(!n1 && !n2) 
                continue;
            else if((!n1 || !n2) || n1->val != n2->val) 
                return false;
            else {
                myqueue.push(n1->left);
                myqueue.push(n2->right);
                myqueue.push(n1->right);
                myqueue.push(n2->left);}
        }
        return true;
    }
};
