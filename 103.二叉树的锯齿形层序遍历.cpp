/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// Definition for a binary tree 

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root) {            
            stack<TreeNode*> st, st1; // 来回入栈 出栈即为题目效果 注意奇偶行确定 入子左节点 子右节点顺序 // st1 为下一行的栈
            st.push(root);
            bool flag = false;
            while (1) {
                vector<int> row;
                while (!st.empty()) {
                    TreeNode* temp = st.top(), *temp1 = temp->left, *temp2 = temp->right;
                    row.push_back(temp->val);
                    st.pop();
                    if(flag) swap(temp1, temp2);
                    if(temp1) st1.push(temp1);
                    if(temp2) st1.push(temp2);
                }
                ans.push_back(row);
                if(st1.empty()) break;
                flag = !flag;
                swap(st, st1);
            }
        }
        return ans;
    }
};
// @lc code=end

// [3,9,10,3,8,15,7]\n
// [3]\n
// [3,9]\n

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool isOrderLeft = true;

        while (!nodeQueue.empty()) {
            deque<int> levelList;
            int size = nodeQueue.size();
            for (int i = 0; i < size; ++i) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if (isOrderLeft) {
                    levelList.push_back(node->val);
                } else {
                    levelList.push_front(node->val);
                }
                if (node->left) {
                    nodeQueue.push(node->left);
                }
                if (node->right) {
                    nodeQueue.push(node->right);
                }
            }
            ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
            isOrderLeft = !isOrderLeft;
        }

        return ans;
    }
};

// 二刷
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        stack<TreeNode*> st, st1;
        if(root) st.push(root);
        bool flag = true;
        while (!st.empty()) {
            vector<int> v;
            while(!st.empty()) {
                TreeNode* t = st.top();
                st.pop();
                v.push_back(t->val);
                if(flag) {
                    if(t->left) st1.push(t->left);
                    if(t->right) st1.push(t->right);
                } else {
                    if(t->right) st1.push(t->right);
                    if(t->left) st1.push(t->left);
                }
            }
            flag = ~flag;
            ans.push_back(v);
            swap(st1, st);
        }
        return ans;
    }
};