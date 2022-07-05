// https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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
    TreeNode* myfun(vector<int>& pre, vector<int>& vin, int l1, int r1, int l2, int r2) {
        if(l1 > r1) return nullptr;
        TreeNode* root = new TreeNode(pre[l1]);
        int k = l2;
        while (vin[k] != pre[l1]) k++;
        k -= l2; // 左子树长度
        root->left = myfun(pre, vin, l1+1, l1+k, l2, l2+k-1);
        root->right = myfun(pre, vin, l1+k+1, r1, l2+k+1, r2);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()) return nullptr;
        int k = 0;
        while (vin[k] != pre[0]) k++;
        TreeNode* root = new TreeNode(pre[0]);
        root->left = myfun(pre, vin, 1, k, 0, k-1);
        root->right = myfun(pre, vin, k+1, pre.size()-1, k+1, vin.size()-1);
        return root;
    }
};