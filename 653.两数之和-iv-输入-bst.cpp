/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 */

#include <vector>
#include <iostream>
#include <unordered_set>
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
// 中序遍历 root->val 为递增
class Solution {
private:
    unordered_set<int> myset;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root) {
            if(findTarget(root->left, k))
                return true;
            if(myset.find(k - root->val) != myset.end())
                return true;
            myset.insert(root->val);
            if(findTarget(root->right, k))
                return true;
        }
        return false;
    }
};
// @lc code=end
// [1,null,4]\n3
