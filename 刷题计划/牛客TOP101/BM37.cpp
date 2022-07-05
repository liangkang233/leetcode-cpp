// https://www.nowcoder.com/practice/d9820119321945f588ed6a26f0a6991f?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        if(p < q)
            swap(p, q);
        else if(p == q)
            return p;

        if(p == root->val || q == root->val || (p>root->val && q < root->val))
            return root->val;
        else if(q < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        else {
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};