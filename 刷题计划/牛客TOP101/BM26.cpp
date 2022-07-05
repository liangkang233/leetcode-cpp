// https://www.nowcoder.com/practice/04a5560e43e24e9db4595865dc9c63a3?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
	struct TreeNode *left;
	struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        if(root) que.push(root);
        while (!que.empty()) {
            vector<int> temp;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* t = que.front();
                que.pop();
                temp.push_back(t->val);
                if(t->left) que.push(t->left);
                if(t->right) que.push(t->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};