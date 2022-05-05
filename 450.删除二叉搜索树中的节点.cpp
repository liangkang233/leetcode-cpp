/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// Definition for a binary tree node.
#include <iostream>
#include <vector>
#include <queue>
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

// 树为二叉搜索树 即左子树皆小于等于 root, 右子树皆大于等于root
// 使用二分 时间复杂logn 即为二叉树层高
class Solution {
public:
    TreeNode* min_node(TreeNode* node) {
        TreeNode* temp = node;
        while (temp->left)
            temp = temp->left;
        return temp;
    }
    TreeNode* deleteMin(TreeNode* node) {
        if(node->left) {
            node->left = deleteMin(node->left);
            return node;
        }
        return node->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return nullptr;
        if (key < root->val) { // 待删除节点在左子树中
            root->left = deleteNode(root->left, key);
            return root;
        } else if (key > root->val) { // 待删除节点在右子树中
            root->right = deleteNode(root->right, key);
            return root;
        } else {  // 当前节点 root 为待删除节点
            if (root->left == nullptr)
                return root->right;
            else if (root->right == nullptr)
                return root->left;
            else { // 左右子树都存在，返回（右子树最左叶子）最小值 作为新的根 另一种做法返回左子树最大值
                TreeNode* New = min_node(root->right);
                New->right = deleteMin(root->right);
                // 这里要注意 一定要先赋值右子树 再赋值左子树 因为现在的 New 还在root某个右子树节点上 New为右树最小值 左树为空
                // 此时先添加左子树 再New->right = deleteMin 会恰好把New的左节点 接到New自身上 形成环
                New->left = root->left; 
                delete root;
                return New;
            }
        }
    }
};
// 注意 节点 释放内存 需要把上层节点的指向 子树指针 置空
// @lc code=end

// [7,5,10,2,6,null,null,1,4,null,null,null,null,3]\n5
// [7,5,10,2,6,null,null,1,4,null,null,null,null,3]\n7
// [7,5,10,2,6,null,null,1,4,null,null,null,null,3]\n2


// 这里给出两种优化方案

// 优化1: 没必要 将右树中的最小节点替换上来 会增加操作   直接找到root节点后 return root的右节点 root左节点 归到root右节点的最小值 的左节点
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (key < root->val) {
            TreeNode* left = deleteNode(root->left, key);
            root->left = left;
        } else if (key > root->val) {
            TreeNode* right = deleteNode(root->right, key);
            root->right = right;
        } else {
            TreeNode* left = root->left;
            TreeNode* right = root->right, *ans = right;
            //寻找右侧最小的叶子节点
            while (right && right->left) {
                right = right->left;
            }
            delete root;
            //如果存在右侧最小的叶子节点，将root的左子树拼接到右侧最小叶子节点的左子树
            if (right) {
                right->left = left;
                return ans;
            } else {//如果不存在右侧最小的叶子节点，root的右子树为空，直接返回左子树
                return left;
            }
        }
        return root;
    }
};

// 优化方案2
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return root;
    if(key<root->val)   root->left=deleteNode(root->left,key);
    if(key>root->val)   root->right=deleteNode(root->right,key);
    if(key==root->val){
        if(!root->left&&!root->right)   return NULL; // 省去了删除root节点的步骤 delete root
        if(root->left&&!root->right)    return root->left; // delete root
        if(!root->left&&root->right)    return root->right; // delete root
        TreeNode* temp=root->right;
        // 优化在于 找到需要删除节点root后 找到需要替换的节点 temp。直接对root val赋值temp最小值 再调用deleteNode 删掉temp的val
        // 由于temp val 其值为最小值 其左树为空 再次调用 deleteNode 必定能够直接删除 （上三种情况）
        while(temp->left)   
            temp=temp->left;
        root->val=temp->val;
        root->right=deleteNode(root->right,root->val);
    }
    return root;
}