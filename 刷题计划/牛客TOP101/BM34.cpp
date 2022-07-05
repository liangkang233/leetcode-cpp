// https://www.nowcoder.com/practice/a69242b39baf45dea217815c7dedb52b?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return bool布尔型
     */
    bool mydfs(TreeNode* root, int l, int r) {
        if(!root) 
            return true;
        else if(root->val <= l || root->val >= r)
            return false;
        return mydfs(root->left, l, root->val) && mydfs(root->right, root->val, r);
    }
    bool isValidBST(TreeNode* root) {
        // if(root->left && (root->val <= root->left->val || !isValidBST(root->left)) ) return false;
        // if(root->right && (root->val >= root->right->val || !isValidBST(root->right)) ) return false;
        if(root)
            return mydfs(root->left, INT_MIN, root->val) && mydfs(root->right, root->val, INT_MAX);
        return true;
    }
};