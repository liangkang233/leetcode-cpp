// https://www.nowcoder.com/practice/e0cc33a83afe4530bcec46eba3325116?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
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
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    bool mydfs(TreeNode* root, int t, vector<int>& path) {
        if(!root) 
            return false;
        path.push_back(root->val);
        if (root->val == t)
            return true;
        if (mydfs(root->left, t, path) || mydfs(root->right, t, path))
            return true;
        path.pop_back();
        return false;
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        if(o1 == o2)
            return o1;
        vector<int> path1, path2;
        mydfs(root, o1, path1);
        mydfs(root, o2, path2);
        int ans;
        for (int i = 0; i < min(path1.size(), path2.size()); i++) {
            if(path1[i] == path2[i])
                ans = path1[i];
            else 
                break;
        }
        return ans;
    }
};