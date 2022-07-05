/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// Definition for a binary tree node.
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

// 正确dfs做法 按照先右后左的顺序进行dfs 最先到该深度的节点即为最右节点
void mydfs1(vector<int>& ans, TreeNode* root, int depth) {
    if(depth == ans.size())
        ans.push_back(root->val);
    if(root->right)
        mydfs1(ans, root->right, depth+1);
    if(root->left)
        mydfs1(ans, root->left, depth+1);
}

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root)
            mydfs1(ans, root, 0);
        return ans;
    }
};
// @lc code=end
// [1,2,3,null,5,null,4]\n
// [1,2,null,3]\n
// [1,2,3,4]\n


// 错误 [1,2,3,4]无法通过 理解错题意了
void mydfs(vector<int>& ans, TreeNode* root) {
    ans.push_back(root->val);
    if(root->right)
        mydfs(ans, root->right);
    else if(root->left)
        mydfs(ans, root->left);
}


// bfs效率较差  103题 栈的话必须用两个
// 此处队列分层遍历的话可以只用一个
void mybfs(vector<int>& ans, TreeNode* root) {
    queue<TreeNode*> que, que1;
    que.push(root);
    int tail = -1;
    // while (1) {
    //     while (!que.empty()) {
    //         TreeNode* now = que.front();
    //         que.pop();
    //         tail = now->val;
    //         if(now->left) que1.push(now->left);
    //         if(now->right) que1.push(now->right);
    //     }
    //     ans.push_back(tail);
    //     if(que1.empty())    break;
    //     swap(que, que1);
    // }
    while (!que.empty()) {
        int len = que.size();
        for (int i = 0; i < len; i++) {
            TreeNode* now = que.front();
            que.pop();
            tail = now->val;
            if(now->left) que.push(now->left);
            if(now->right) que.push(now->right);
        }
        ans.push_back(tail);
    }
}

// 二刷
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> que;
        if(root)
            que.push(root);
        int level = que.size(), n = 0;
        while (!que.empty()) {
            TreeNode* now = que.front();
            que.pop();
            if(now->left)
                que.push(now->left);
            if(now->right)
                que.push(now->right);
            n++;
            if(n == level) {
                // cout << level << " " << now->val<< endl;
                n = 0;
                level = que.size();
                ans.push_back(now->val);
            }
        }
        return ans;
    }
};

// 三刷 用dfs更省空间 好好温习下
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> que;
        if(root)
            que.push(root);
        while (!que.empty()) {
            int size = que.size();
            que.pop();
            TreeNode* temp;
            for (int i = 0; i < size; i++) {
                temp = que.front();
                if(temp->left)
                    que.push(temp->left);
                if(temp->right)
                    que.push(temp->right);
            }
            v.push_back(temp->val);
        }
        return v;
    }
};