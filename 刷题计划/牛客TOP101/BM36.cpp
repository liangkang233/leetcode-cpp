// https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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

// 题目 不需要考虑 它是 搜索二叉树
// 只用计算深度即可
class Solution {
public:
    int mydfs(TreeNode* root, int depth) { // 返回-1 表示不为平衡树 否则返回最大深度
        if(!root)
            return depth;
        int ld = mydfs(root->left, depth+1);
        int rd = mydfs(root->right, depth+1);
        if(ld < 0 || rd < 0 || abs(ld - rd) > 1)
            return -1;
        return max(ld, rd);
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) return true;
        int ld = mydfs(pRoot->left, 1);
        int rd = mydfs(pRoot->right, 1);
        if(ld < 0 && rd < 0 || abs(ld - rd) > 1)
            return false;
        return true;
    }
};


// 一般的平衡二叉树版本
class Solution {
public:
    int mydfs(TreeNode* root, int v_min, int v_max, int depth) { // 返回该搜索树最大深度 如果不是二叉搜索树 则返回-1
        if(!root)
            return depth;
        else if(root->val <= v_min || root->val >= v_max)
            return -1;
        int ld = mydfs(root->left, v_min, root->val, depth+1);
        int rd = mydfs(root->right, root->val, v_max, depth+1);
        if(ld < 0 || rd < 0 || abs(ld - rd) > 1)
            return -1;
        return max(ld, rd);
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) return true;
        int ld = mydfs(pRoot->left, INT_MIN, pRoot->val, 1);
        int rd = mydfs(pRoot->right, pRoot->val, INT_MAX, 1);
        if(ld < 0 && rd < 0 || abs(ld - rd) > 1)
            return false;
        return true;
    }
};