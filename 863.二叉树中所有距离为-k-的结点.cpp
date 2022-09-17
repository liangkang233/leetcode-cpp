/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
class Solution {
private:
    TreeNode* T;
public:
    void findfa(TreeNode* curr, TreeNode* target, unordered_map<TreeNode*, TreeNode*>& fa) {
        if(curr == target) T = target;
        if(curr->left) {
            fa[curr->left] = curr;
            findfa(curr->left, target, fa);
        }
        if(curr->right) {
            fa[curr->right] = curr;
            findfa(curr->right, target, fa);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root) {
            unordered_map<TreeNode*, TreeNode*> fa;
            fa[root] = nullptr;
            findfa(root, target, fa); // 构建父节点查询表 并查询节点T
            // 以左右父节点 三个方向进行层序遍历
            queue<TreeNode*> que;
            unordered_set<TreeNode*> ms; // 防止重复遍历 这里可以压缩空间不需要 只要每个节点记录自己遍历的父节点 不要遍历回去即可
            ms.insert(T);
            que.push(T);
            // cout << T->val << "find!" << endl;
            while (!que.empty()) {
                if(!k) {
                    while (!que.empty()) {
                        ans.push_back(que.front()->val);
                        que.pop();
                    }
                }
                int size = que.size();
                for (int i = 0; i < size; i++) {
                    TreeNode* curr = que.front();
                    que.pop();
                    // cout << curr->val << endl;
                    if(fa[curr] && ms.find(fa[curr]) == ms.end()) {
                        que.push(fa[curr]);
                        ms.insert(fa[curr]);
                    } if(curr->left && ms.find(curr->left) == ms.end()) {
                        que.push(curr->left);
                        ms.insert(curr->left);
                    } if(curr->right && ms.find(curr->right) == ms.end()) { 
                        que.push(curr->right);
                        ms.insert(curr->right);
                    }
                }
                k--;
            }
        }
        return ans;
    }
};
// @lc code=end

