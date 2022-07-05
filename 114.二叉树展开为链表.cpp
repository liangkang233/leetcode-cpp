/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

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
    TreeNode* mydfs(TreeNode* root) { // 返回链表尾部 lt rt 代表左右子链表尾部
        TreeNode* l = root->left, *r = root->right, *lt = root, *rt = root;
        if(l) {
            root->left = nullptr;
            root->right = l;
            lt = mydfs(l);
        }
        if(r) {
            lt->right = r;
            rt = mydfs(r);
        }
        return rt == root ? lt : rt; // rt为root 返回可能为尾节点的左子链表尾部
    }
    void flatten(TreeNode* root) {
        if(root)
            mydfs(root);
    }
};
// @lc code=end
// [1,2,null,3,4,5]\n
