/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

#include <iostream>
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
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 1;
        ListNode* curr = head;
        if(head) {
            for (; curr->next!=nullptr; size++)
                curr=curr->next;
            curr->next=head; // 缝合
            k = size - (k % size); //实际size要加1 [0,size-1]
            while (k-- > 0)   // 拆开
                curr=curr->next;
            head = curr->next;
            curr->next = nullptr;
        }
        return head;
    }
};
// @lc code=end

// [1,2,3,4,5]\n0
