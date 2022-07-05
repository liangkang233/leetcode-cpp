// https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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

// 中序遍历
class Solution {
private:
    TreeNode* P;
public:
    void mydfs(TreeNode* root) {
        if(!root) return;
        mydfs(root->left);
        P->right = root;
        root->left = P;
        P = root;
        mydfs(root->right);
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if(!pRootOfTree) return nullptr;
        TreeNode myhead(-1);
        P = &myhead;
        mydfs(pRootOfTree);
        myhead.right->left = nullptr;
        return myhead.right;
    }
};