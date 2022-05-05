/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

#include <limits>
#include <iostream>
#include <unordered_map>
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
    int ans = INT_MIN;
public:
    // 后序遍历 递归查询左右子树的最大路径和 并判断当前节点的最大路径和
    int mydfs(TreeNode* root) {
        if(root) {
            int L_max = 0, R_max = 0;
            L_max = max(L_max, mydfs(root->left));
            R_max = max(R_max, mydfs(root->right));
            // cout << L_max << " " <<R_max << " " <<root->val << endl;
            ans = max(ans, L_max + R_max + root->val);
            return max(L_max, R_max) + root->val;
        }
        return INT_MIN;
    }
    int maxPathSum(TreeNode* root) {
        mydfs(root);
        return ans;
    }
};
// @lc code=end
// [1,2,1]\n
// [-10,9,20,null,null,15,7]
// [1,2,3,null,3,null,5,5,-123,34,45,-12,34,-453,-1,2,-54]
