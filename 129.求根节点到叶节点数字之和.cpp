/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int ans = 0;
public:
    void mydfs(TreeNode* now, int temp) {
        if (!now) ;
        else if (!now->left && !now->right) {
            // cout << temp*10 + now->val << endl;
            ans += temp*10 + now->val;
        } else {
            mydfs(now->left, temp*10 + now->val);
            mydfs(now->right, temp*10 + now->val);
        }
    }
    int sumNumbers(TreeNode* root) {
        mydfs(root, 0);
        return ans;
    }
};
// @lc code=end
// [1,1,1]\n

class Solution {
private:
    int ans = 0;
public:
    void mydfs(TreeNode* now, int temp) {
        if (!now->left && !now->right) {
            cout << temp*10 + now->val << endl;
            ans += temp*10 + now->val;
        } else {
            if(now->left)
                mydfs(now->left, temp*10 + now->val);
            if(now->right)
                mydfs(now->right, temp*10 + now->val);
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root)
            mydfs(root, 0);
        return ans;
    }
};
