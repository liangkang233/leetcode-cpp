/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

#include <iostream>
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
private:
    int sum = 0;
public:
    void mydfs(TreeNode* now) {
        if(now) {
            sum += now->val;
            mydfs(now->left);
            mydfs(now->right);
        }
    }
    void mydfs1(TreeNode* now) {
        if(now) {
            mydfs1(now->left);
            // cout << now->val << " " << sum << endl;
            sum -= now->val;
            now->val += sum;
            mydfs1(now->right);
        }
    }
    // 直接在原树修改
    TreeNode* convertBST(TreeNode* root) {
        mydfs(root);
        mydfs1(root);
        return root;
    }
};
// @lc code=end
// []\n
// [0,null,1]

// 创建新树 前序创节点 中序添加值
class Solution {
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* now = nullptr;
        if(root) {
            now = new TreeNode(root->val); // 先复制节点
            // 中序遍历即为 搜索树的正序顺序
            now->right = convertBST(root->right);
            now->val += sum;
            sum = now->val;
            now->left = convertBST(root->left);
        }
        return now;
    }
};