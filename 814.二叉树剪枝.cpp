/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
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
    TreeNode* mydfs(TreeNode* now) {
        if(now->left) {
            if(!mydfs(now->left))
                now->left = nullptr;
        }
        if(now->right) {
            if(!mydfs(now->right))
                now->right = nullptr;
        }
        if(!now->val && !now->left && !now->right){
            // delete now; // 注意题目中给的root 都是申请的局部变量非堆空间 不需要释放now 否则异常
            return nullptr;
        }return now;
    }
    TreeNode* pruneTree(TreeNode* root) {
        TreeNode head = TreeNode(1, root, nullptr);
        return mydfs(&head)->left;
    }
};
// @lc code=end

            
class Solution {
public:
    TreeNode* mydfs(TreeNode* now) {
        if(now->left && !mydfs(now->left))
            now->left = nullptr;
        if(now->right && !mydfs(now->right))
            now->right = nullptr;
        if(!now->val && !now->left && !now->right) {
            // delete now; // 注意题目中给的root 都是局部变量非堆空间 不需要释放now 否则异常
            return nullptr;
        }
        return now;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root)
            return mydfs(root);
        return root;
    }
};