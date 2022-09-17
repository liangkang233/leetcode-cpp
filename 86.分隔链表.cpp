/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

// Definition for singly-linked list.
    struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // L R 是左右区间的尾部 Lhead Rhead 是左右区间的头
        ListNode *L = nullptr, *R = nullptr, *Lhead = nullptr, *Rhead = nullptr;
        while(head) {
            if(head->val < x) {
                if(!Lhead) Lhead = head;
                if(L) L->next = head;
                L = head;
            } else {
                if(!Rhead) Rhead = head;
                if(R) R->next = head;
                R = head;
            }
            head = head->next;
        }
        if(R)   R->next = nullptr;
        if(!L)  return Rhead;
        L->next = Rhead;
        return Lhead;
    }
};
// @lc code=end
