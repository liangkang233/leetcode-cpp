/*
 * @lc app=leetcode.cn id=285 lang=cpp
 *
 * https://leetcode-cn.com/problems/inorder-successor-in-bst/
 * 
 * https://leetcode-cn.com/problems/P5rCT8/
 * 
 * [708] 循环有序链表
 */
#include <iostream>
using namespace std;

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
    int target;
public:
    TreeNode* mydfs(TreeNode* now) {
        TreeNode* next = nullptr;
        if(now) {
            mydfs(now->left);
            cout << now->val;
            if(now->val > target)
                return now;
            mydfs(now->right);            
        }
        return next;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        target = p->val;
        return mydfs(root);
    }
};
// @lc code=end
