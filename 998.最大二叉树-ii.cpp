/*
 * @lc app=leetcode.cn id=998 lang=cpp
 *
 * [998] 最大二叉树 II
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
// 注意理清题意 最大树 是 根节点大于左右子树最大值
// 这里不用类似堆的数组做法 从子节点向上递归查添加 直接从上往下找

// 654 二叉树 按照这个思路建树。。。 无语了
// 给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
// 创建一个根节点，其值为 nums 中的最大值。
// 递归地在最大值 左边 的 子数组前缀上 构建左子树。
// 递归地在最大值 右边 的 子数组后缀上 构建右子树。

class Solution {
public:
    TreeNode* mydfs(TreeNode* root, int val, int flag) { // flag 标记该树是左树 还是右树
        if(!root) {
            return new TreeNode(val, nullptr, nullptr);
        } else if(val > root->val) {
            return new TreeNode(val, root, nullptr);
        } else {
            if(flag == 0) {
                root->left = mydfs(root->left, val, 0);
                return root;
            } else {
                root->right = mydfs(root->right, val, 1);
                return root;
            }
        }
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        return mydfs(root, val, 1); // 初始对右树 判断
    }
};
// @lc code=end

// [5,2,4,null,1]\n3
// [5,2,3,null,1]\n4