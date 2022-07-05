/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

#include <iostream>
#include <queue>
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
// 应该是 反向的动态规划 和 深度遍历 直接遍历会超时 优化下
// return 自身以及下一级的 返回值 减少 原版dfs 同一个节点递归两次 时间复杂度指数增加
class Solution {
public:
    pair<int, int> mydfs(TreeNode* root) {
        if(!root) return make_pair(0, 0);
        // first 表示节点子节点的最大递归值 second表示节点孙子节点最大递归值
        pair<int, int> l = mydfs(root->left), r = mydfs(root->right);
        // fisrt 为 second 与孙子节点加上当前val的较大值, second 为 l.first + r.first
        int last = l.first + r.first;
        int now = root->val + l.second + r.second;
        return make_pair(max(now, last), last);
    }
    int rob(TreeNode* root) {
        return mydfs(root).first;
    }
};
// @lc code=end
// [1,null,2,null,3,null,10,null,1,null,1,null,12]\n
// [2,1,3,null,4]\n
// [79,99,77,null,null,null,69,null,60,53,null,73,11,null,null,null,62,27,62,null,null,98,50,null,null,90,48,82,null,null,null,55,64,null,null,73,56,6,47,null,93,null,null,75,44,30,82,null,null,null,null,null,null,57,36,89,42,null,null,76,10,null,null,null,null,null,32,4,18,null,null,1,7,null,null,42,64,null,null,39,76,null,null,6,null,66,8,96,91,38,38,null,null,null,null,74,42,null,null,null,10,40,5,null,null,null,null,28,8,24,47,null,null,null,17,36,50,19,63,33,89,null,null,null,null,null,null,null,null,94,72,null,null,79,25,null,null,51,null,70,84,43,null,64,35,null,null,null,null,40,78,null,null,35,42,98,96,null,null,82,26,null,null,null,null,48,91,null,null,35,93,86,42,null,null,null,null,0,61,null,null,67,null,53,48,null,null,82,30,null,97,null,null,null,1,null,null]\n

// 直接 dfs 超时
// class Solution {
// public:
//     int rob(TreeNode* root) {
//         if(!root) return 0;
//         int next = 0;
//         if(root->left)
//             next += rob(root->left->left) + rob(root->left->right);
//         if(root->right)
//             next += rob(root->right->left) + rob(root->right->right);
//         return max(root->val + next, rob(root->left) + rob(root->right));
//     }
// };

// 又是打家劫舍 这次换皮为数 由题意知道 为了答案最大化 
// 每次大街肯定是一层一层的打劫。 动态规划 和 层序遍历 (思路错误!)
/* class Solution {
public:
    int mydfs(TreeNode* root, int last, int now) {
        return now;
    }
    int rob(TreeNode* root) {
        int last = 0, now = 0;
        queue<TreeNode*> myque;
        if(root) myque.push(root);
        while (!myque.empty()) {
            int size = myque.size(), val = 0, temp;
            for (int i = 0; i < size; i++) {
                TreeNode* t = myque.front();
                myque.pop();
                val += t->val;
                if(t->left)
                    myque.push(t->left);
                if(t->right)
                    myque.push(t->right);
            }
            temp = now;
            now = max(last + val, now);
            last = temp; // 动态规划 val 为当前值 now last为上两个层序的最大值
        }
        return now;
    }
}; */