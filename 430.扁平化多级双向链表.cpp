/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

#include <iostream>
#include <queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// @lc code=start
class Solution {
public:
    Node* mydfs(Node* curr) { // 返回该条扁平链表的末尾
        if(!curr)
            return nullptr;
        Node* right = curr->next;
        Node* temp1 = mydfs(curr->child); //child支线尾节点
        if(temp1) {
            temp1->next = right; // child 支线的末尾连上 原来next
            if(right) //这里被坑了下
                curr->next->prev = temp1;
            curr->next = curr->child; // 原 child 改为 next
            curr->child->prev = curr;
            curr->child = nullptr;
        }
        Node* temp2 = mydfs(right); //next支线尾节点
        if(temp2)
            return temp2;
        else if(temp1)
            return temp1;
        return curr;
    }

    // dfs 特别像二叉树的先序遍历
    Node* flatten(Node* head) {
        // if(head != nullptr)
        mydfs(head);
        return head;
    }
};
// @lc code=end

// [1,null,2,null,3,null]\n