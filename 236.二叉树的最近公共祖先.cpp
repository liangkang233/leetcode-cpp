/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 如果 root 为空 表示该递归无效节点直接 return root 空
        if(!root || root == p || root == q)
            return root;
        TreeNode *temp1, *temp2;
        temp1 = lowestCommonAncestor(root->left, p, q);
        temp2 = lowestCommonAncestor(root->right, p, q);
        if(temp1 && temp2) // 若两边节点都有 则当前节点即为交叉节点
            return root;
        return temp1 ? temp1 : temp2;
    }
};
// @lc code=end
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n4
// [3,5,1,6,2,0,8,null,null,7,4]\n0\n8
// [1,2]\n1\n2


class Solution {
public:
    // dfs 优先左子树 再右子树查找
    bool mydfs(vector<TreeNode*>& path, TreeNode* now, TreeNode* target) {
        if(now == target)
            return true;
        if(now->left) {
            path.push_back(now->left);
            if(mydfs(path, now->left, target))
                return true;
            path.pop_back();
        }
        if(now->right) {
            path.push_back(now->right);
            if(mydfs(path, now->right, target))
                return true;
            path.pop_back();
        }
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1{root}, path2{root};
        mydfs(path1, root, p);
        mydfs(path2, root, q); 
        TreeNode* ans;
        for (int i = 0; i<path1.size() && i<path2.size() && path1[i]==path2[i]; i++) {
            ans = path1[i];
        }
        return ans;
    }
};