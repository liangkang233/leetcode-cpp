/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 * 假设一个二叉搜索树具有如下特征：
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 */
#include <iostream>
#include <queue>
#include <stack>
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
    // 递归 dfs
    bool dfs(TreeNode* temp, long long lower, long long upper) {
        if (!temp)
            return true;
        if(!(temp->val > lower && temp->val < upper))
            return false;
        return dfs(temp->left, lower, temp->val) && dfs(temp->right, temp->val, upper);
    }

    bool isValidBST(TreeNode* root) {
        if (!root) 
            return false;
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};
// @lc code=end

class Solution2 {
public:
    /*     
    中序遍历是二叉树的一种遍历方式，它先遍历左子树，再遍历根节点，最后遍历右子树。
    而我们二叉搜索树保证了左子树的节点的值均小于根节点的值，根节点的值均小于右子树的值
    因此中序遍历以后得到的序列一定是升序序列。 
    中序举例：
        left
        cout
        right
    官方用栈实现，递归也可
    */ 
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long long inorder = LLONG_MIN;

        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
            if (root -> val <= inorder) {
                return false;
            }
            inorder = root -> val;
            root = root -> right;
        }
        return true;
    }
};

class Solution3 {
public:
    //递归实现 中序
    long long pre = LLONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root)   return true;

        if (!isValidBST(root->left) )
            return false;

        if(root->val <= pre)
            return false;
        pre = root->val;

        if( !isValidBST(root->right) )
            return false;

        return true;
    }
};

/* 此答案思路错误不合题意，此处代码仅仅判断子节点和当前节点
如果该二叉树的左子树不为空，则左子树上所有节点的值均小于它的根节点的值； 
若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
它的左右子树也为二叉搜索树。 */
class Solution1 {
public:
    // bfs
    bool isValidBST(TreeNode* root) {
        if (!root) 
            return false;
        queue<TreeNode* > myqueue;
        myqueue.push(root);
        TreeNode* temp,* tempL,* tempR;
        while(!myqueue.empty()) {
            temp = myqueue.front();
            myqueue.pop();
            if(temp->left != nullptr) {
                tempL = temp->left;
                if(temp->val <= tempL->val)
                    return false;
                myqueue.push(tempL);
            }
            if(temp->right != nullptr) {
                tempR = temp->right;
                if(temp->val >= tempR->val)
                    return false;
                myqueue.push(tempR);
            }
        }
        return true;
    }
};