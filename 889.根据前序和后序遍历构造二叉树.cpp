/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

// 注意题中说明 二叉树中的各个值不相同,不需要考虑不成立的情况
// 前序/后序+中序序列可以唯一确定一棵二叉树，只知道前序和后序不唯一确定
// 前序是 root + 左树节点 + 右树节点
// 后序是 左树节点 + 右树节点 + root
// 所以后序的倒数第二个是前序中右树的根节点 前序的第二个是后续的前树的根节点最后一位 如此递推就有规律
class Solution {
public:
    // l1 r1限定pre的子树区域，l2 r2限定post的子树区域。
    // 此法默认优先生成左子树（即只有一边子树时默认是左子树）
    TreeNode* build_tree(vector<int>& pre, vector<int>& post, int l1, int r1, int l2, int r2) {
        if(l1 > r1)
            return nullptr;
        TreeNode *root = new TreeNode(pre[l1]); //或post[r2]
        for (int i = r2-1; i >= l2; i--) {
            if(pre[l1+1] == post[i]) {
                int len = i - l2;
                root->left = build_tree(pre, post, l1+1, l1+len+1, l2, i);         
                root->right = build_tree(pre, post, l1+len+2, r1, i+1, r2-1);
                break;
            }
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* ans = build_tree(preorder, postorder, 0, postorder.size()-1, 0, preorder.size()-1);
        return ans;
    }
};
// @lc code=end

