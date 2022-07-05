/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
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
    unordered_map<int, int> mp;
    int maxCount = 0;
public:
    int mydfs(TreeNode* root) {
        if(!root)   return 0;
        int key = root->val;
        key += mydfs(root->left);
        key += mydfs(root->right);
        mp[key]++;
        maxCount = max(maxCount, mp[key]);
        return key;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        mydfs(root);
        vector<int> ans;
        for (pair<const int, int>& i : mp) {
            // cout << i.first << ":" << i.second << endl;
            if(i.second == maxCount) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
// @lc code=end
// [0,1,2,2,-1,0,2,-2]\n
