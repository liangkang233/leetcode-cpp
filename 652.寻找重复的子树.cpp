/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 */

#include <iostream>
#include <vector>
#include <string>
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
    unordered_map<string, pair<TreeNode*, int>> mp;
public:
    string mydfs(TreeNode* root) {
        if(!root) return "."; 
        // 下面必须加特殊符号 先序遍历 不加连接符号不同种结构可能打出同种字符
        // 例如 [2,1,11,11,null,1]
        string ans = to_string(root->val) +  " " + mydfs(root->left) + " " +  mydfs(root->right);
        // string ans = to_string(root->val) + mydfs(root->left) + mydfs(root->right);
        if(mp.find(ans) == mp.end())  mp[ans] = make_pair(root, 0);
        mp[ans].second++;
        return ans;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        mydfs(root);
        for(auto& i : mp) {
            if(i.second.second > 1)
                ans.push_back(i.second.first);
        }
        return ans;
    }
};
// @lc code=end


// 简洁明了
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int>m;
        vector<TreeNode*>res;
        DFS(root, m, res);
        return res;
    }
    
    string DFS(TreeNode* root, unordered_map<string, int>& m, vector<TreeNode*>& res){
        if(!root) return "";
        string s = to_string(root->val) + "," + DFS(root->left, m, res) + "," + DFS(root->right, m, res);
        if(m[s]++ == 1) res.push_back(root);
        return s;
    }
};

