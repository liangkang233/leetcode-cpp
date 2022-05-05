/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
 */

#include <queue>
#include <iostream>
using namespace std;

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

class CBTInserter {
private:
    TreeNode* root;
    queue<TreeNode*> myque, next_que; // 当前遍历层队列 以及下一层正在补齐的层
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        myque.push(root);
        while (1) {
            if(myque.empty())
                swap(myque, next_que);
            TreeNode* fa = myque.front();
            // cout << fa->val << " *" << endl;
            if(fa->left) // 遍历过程中 只要出现 左、右 子节点不存在即可退出 直到补齐myque队列
                next_que.push(fa->left);
            else
                break;
            if(fa->right) {
                next_que.push(fa->right);
                myque.pop();
            }
            else
                break;
        }
    }
    
    int insert(int val) {
        if(myque.empty())
            swap(myque, next_que);
        TreeNode* fa = myque.front();
        // cout << fa->val << endl;
        if(!fa->left) {
            fa->left = new TreeNode(val);
            next_que.push(fa->left);
        } else {
            fa->right = new TreeNode(val);
            next_que.push(fa->right);
            myque.pop();
        }
        return fa->val;
    }
    
    TreeNode* get_root() {
        return this->root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end
// ["CBTInserter","insert","insert","insert","insert","insert","insert","insert","insert","get_root"]\n[[[1,2,3,4,5,6,7]],[2],[2],[2],[2],[2],[2],[2],[2],[]]\n
// ["CBTInserter","insert","insert","get_root"]\n[[[1,2]],[3],[4],[]]