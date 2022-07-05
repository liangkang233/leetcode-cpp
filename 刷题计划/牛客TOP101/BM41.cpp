// https://www.nowcoder.com/practice/c9480213597e45f4807880c763ddd5f0?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */
    void printTree(TreeNode *root, vector<int>& ans, int depth) {
        if(!root)  return;
        if(depth == ans.size())
            ans.push_back(root->val);
        // cout << root->val << " ";
        printTree(root->right, ans, depth+1);
        printTree(root->left, ans, depth+1);
    }
    TreeNode* myfun(vector<int>& xianxu, vector<int>& zhongxu, int l1, int r1, int l2, int r2) {
        if(l1 > r1) return nullptr;
        TreeNode* root = new TreeNode(xianxu[l1]);
        // cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
        int k = l2;
        while (zhongxu[k] != xianxu[l1]) k++;
        k -= l2; // 左子树长度
        root->left = myfun(xianxu, zhongxu, l1+1, l1+k, l2, l2+k-1);
        root->right = myfun(xianxu, zhongxu, l1+k+1, r1, l2+k+1, r2);
        return root;
    }
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        int k = 0;
        while (zhongxu[k] != xianxu[0]) k++;
        TreeNode* root = new TreeNode(xianxu[0]);
        root->left = myfun(xianxu, zhongxu, 1, k, 0, k-1);
        root->right = myfun(xianxu, zhongxu, k+1, xianxu.size()-1, k+1, zhongxu.size() - 1);
        vector<int> ans;
        printTree(root, ans, 0);
        return ans;
    }
};