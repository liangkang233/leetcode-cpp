/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 */

// Definition for a binary tree node.
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

// @lc code=start
struct link {
    int val;
    link* next;
    link() : val(-1), next(nullptr) {}
    link(int val, link* next) : val(val), next(next) {}
};

class BSTIterator {
public:
    link* li = new link(), *temp = li;
    void mybfs(TreeNode* root) {
        if (root->left)
            mybfs(root->left);
        temp->next = new link(root->val, nullptr);
        temp = temp->next;
        if (root->right)
            mybfs(root->right);
    }
    BSTIterator(TreeNode* root) {
        // 层序遍历的二叉树转为链表 空间复杂度O(2^h) h为树高
        mybfs(root);
    }
    
    int next() {
        li = li->next;
        return li->val;
    }
    
    bool hasNext() {
        return li->next != nullptr;
    }
};
// @lc code=end

// 官方解法 空间复杂度O(h) h为树高
class BSTIterator {
private:
    TreeNode* cur;
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode* root): cur(root) {}
    
    int next() {
        while (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        int ret = cur->val;
        cur = cur->right;
        return ret;
    }
    
    bool hasNext() {
        return cur != nullptr || !stk.empty();
    }
};
// 上述即为 中序的栈实现，下面展示前中后序的栈 遍历 实现
// 前序遍历.  想不出有什么简单的前序后序迭代器
vector<int> preorderTraversal(TreeNode* root) { 
    vector<int> retvec;
    stack<TreeNode*> stk;

    while (root != NULL || !stk.empty()) {
        while (root != NULL) {
            retvec.push_back(root->val);
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        root = root->right;
    }
}

// 中序遍历.
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> retvec;
    stack<TreeNode*> stk;

    while (root != NULL || !stk.empty()) {
        while (root != NULL) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        retvec.push_back(root->val);
        root = root->right;
    }
}

/* 补充: 后序遍历
前序遍历 => 根, 左, 右.
后序遍历 => 左, 右, 根.
仿照前序遍历方法求解出 => 根, 右, 左.
reverse => 得到后序遍历. */
vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    vector<int> vec;
    while (root != NULL || !stk.empty()) {
        while (root != NULL) {
            vec.push_back(root->val);
            stk.push(root);
            root = root->right;
        }
        root = stk.top();
        stk.pop();
        root = root->left;
    }
    reverse(vec.begin(), vec.end());
    return vec;
}