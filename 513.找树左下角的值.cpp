/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        int ans = -1, n = 0, level = 1; // level 对应每层个数
        if(root)    que.push(root);
        while (!que.empty()) {
            TreeNode* now = que.front();
            que.pop();
            if(now->left)
                que.emplace(now->left);
            if(now->right)
                que.emplace(now->right);
            n++;
            if(n == 1) {
                ans = now->val;
                // cout << ans << endl;
            }
            if(n == level) {
                n = 0;
                level = que.size();
            }
        }
        return ans;
    }
};
// @lc code=end
// [1,2,3,4,null,5,6,null,null,7]

// bfs 常规做法 先右树 再左树
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            root=q.front(); // get the value before pop coz pop will not return anyy val
            q.pop();
            if (root->right) q.push(root->right);
            if(root->left) q.push(root->left);
        }
        return root->val;
        
    }
};

// 正确dfs做法 按照先左后右的顺序进行dfs 最先到该深度的节点即为最左节点
class Solution {
private:
    int ans=-1;
public:
    // 按照先左后右的顺序进行dfs 最先到该深度的节点即为最左节点
    void mydfs(int& now, TreeNode* root, int depth) {
        if(depth == now) {
            ans=root->val;
            now++;
        }
        if(root->left)
            mydfs(now, root->left, depth+1);
        if(root->right)
            mydfs(now, root->right, depth+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        int now = 0;
        if(root)
            mydfs(now, root, 0);
        return ans;
    }
};