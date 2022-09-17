/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
 */

#include <queue>
#include <stack>
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



// 二刷 采用栈记录父节点递归路径 初始化的时候需要记录size 即插入时的当前下标
class CBTInserter {
private:
    int size;
    TreeNode* head;
public:
    CBTInserter(TreeNode* root) {
        head = root;
        queue<TreeNode*> que;
        que.push(root);
        size = 0;
        while(!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            if(temp->left)
                que.push(temp->left);
            if(temp->right)
                que.push(temp->right);
            size++;
        }
    }
    int insert(int val) {
        stack<int> st;
        int index = size;
        while(index != 0) {
            st.push(index);
            index = (index-1) / 2;
        }
        TreeNode* fa = head;
        while(st.size() > 1) {
            if(st.top() == 2*index+1) {
                fa = fa->left;
            } else {
                fa = fa->right;
            }
            index = st.top();
            st.pop();
        }
        size++;
        if(st.top() == 2*index+1) {
            fa->left = new TreeNode(val);
        } else {
            fa->right = new TreeNode(val);
        }
        return fa->val;
    }
    
    TreeNode* get_root() {
        return head;
    }
};
