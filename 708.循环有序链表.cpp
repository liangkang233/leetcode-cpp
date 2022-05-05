/*
 * @lc app=leetcode.cn id=708 lang=cpp
 *
 * https://leetcode-cn.com/problems/insert-into-a-sorted-circular-linked-list/
 * 
 * https://leetcode-cn.com/problems/4ueAj6/
 * 
 * [708] 循环有序链表
 */

#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

// @lc code=start
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head) {
            head = new Node(insertVal);
            head->next = head;
        } else {
            Node* Max = head; // 记录遍历节点中 next-val 满足大于等于MAX 且next小于自身节点 最小值即为Max->next
            Node* now = head->next;
            while (now != head) {
                if(now->val >= Max->val && now->next->val < now->val) // 关键
                    Max = now;
                now = now->next;
            }
            // cout << "MAXval " << Max->val << endl;
            if(insertVal >= Max->val || insertVal <= Max->next->val) {
                Max->next = new Node(insertVal, Max->next);
            } else {
                now = Max->next; // now 为最小值
                // cout << now->next->val << endl;
                while (now->next->val < insertVal)
                    now = now->next;
                now->next = new Node(insertVal, now->next);
            }
        }
        return head;
    }
};
// @lc code=end

