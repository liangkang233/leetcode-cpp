/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start
// bfs解法 两个队列
// 其实可以优化为1个队列 记录遍历开始时size for 到最后时加个null结尾  效果差不多
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> queue1, queue2;
        if(root!=nullptr) {
            queue1.push(root);
            while (!queue1.empty() || !queue2.empty()) {
                Node* temp = queue1.front();
                if(temp->left)
                    queue2.push(temp->left);
                if(temp->right)
                    queue2.push(temp->right);
                queue1.pop();
                if(queue1.empty()) {
                    temp->next = nullptr;
                    swap(queue1, queue2);
                }
                else
                    temp->next = queue1.front();
            }
        }
        return root;
    }
};
// @lc code=end
// [1]\n
// [1,3,4,5,6,7,null,100,54,null,56,7,8,24,null,5,6,2,null,53]\n

// 官方的进阶做法，空间复杂度O(1)
class Solution {
public:
    void handle(Node* &last, Node* &p, Node* &nextStart) {
        if (last) {
            last->next = p;
        } 
        if (!nextStart) {
            nextStart = p;
        }
        last = p;
    }

    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        Node *start = root;
        while (start) {
            Node *last = nullptr, *nextStart = nullptr; // 记录当前遍历下一层的最后一个节点 开始节点
            for (Node *p = start; p != nullptr; p = p->next) {
                if (p->left) {
                    handle(last, p->left, nextStart);
                }
                if (p->right) {
                    handle(last, p->right, nextStart);
                }
            }
            start = nextStart;
        }
        return root;
    }
};