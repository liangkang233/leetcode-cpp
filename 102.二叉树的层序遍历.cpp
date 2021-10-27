/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
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
    vector<vector <int>> ans;
    queue<TreeNode *> myque;

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) 
            return ans;
        myque.push(root);

        while ( !myque.empty()) {
            ans.push_back(vector<int> ());
            int N = myque.size(), num = ans.size();
            
            for (int i = 0; i < N; i++) {
                TreeNode* temp = myque.front();
                myque.pop();
                ans[num-1].push_back(temp->val);
                if(temp->left != nullptr)
                    myque.push(temp->left);
                if(temp->right != nullptr)
                    myque.push(temp->right);
            }
        }
        return ans;
    }
};
// @lc code=end

