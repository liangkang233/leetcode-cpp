// https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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

// 注意题中判断是否对称 不是相等
bool mydfs(TreeNode* T1, TreeNode* T2) {
    if(!T1 || !T2)
        return !T1 && !T2;
    else if(T1->val != T2->val)
        return false;
    return mydfs(T1->left, T2->right) && mydfs(T1->right, T2->left);
    // return mydfs(T1->left, T2->left) && mydfs(T1->right, T2->right);
}
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot) {
        if(!pRoot) return true;
        return mydfs(pRoot->left, pRoot->right);
    }
};