/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

#include <iostream>
#include <vector>
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

// 前序 = root, 左子树前序, 右子树节点 
// 中序 = 左子树中序，root，右子树中序
// @lc code=start

TreeNode* mydfs(vector<int>& preorder, vector<int>& inorder, int pre_L, int pre_R, int in_L, int in_R) {
    // if(pre_L > pre_R || in_L > in_R) // 和下式等价
    if(pre_L > pre_R)
        return nullptr;
    int index = in_L, count = 0;
    for (; index <= in_R && preorder[pre_L] != inorder[index]; index++);
    count = index - in_L; // 左节点个数
    // 如果越界即左根为空
    TreeNode* left = mydfs(preorder, inorder, pre_L+1, pre_L+count, in_L, index-1);
    // 如果越界即右根为空
    TreeNode* right = mydfs(preorder, inorder, pre_L+count+1, pre_R, index+1, in_R); 
    return new TreeNode(preorder[pre_L], left, right);
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return mydfs(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
// @lc code=end

// [3,9,10,20,15,7]\n[10,9,3,15,20,7]
// [1]\n[1]