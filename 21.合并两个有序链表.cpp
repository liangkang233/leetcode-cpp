/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

#include <iostream>
#include <climits>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head = ListNode(), *h = &head;
        while (list1 || list2) {
            int a = list1 ? list1->val : INT_MAX;
            int b = list2 ? list2->val : INT_MAX;
            if(a <= b) {
                h->next = list1;
                list1 = list1->next;
            } else {
                h->next = list2;
                list2 = list2->next;
            }
            h = h->next;
        }
        return head.next;
    }
};
// @lc code=end

// 优雅写法
ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
    if ((!a) || (!b)) return a ? a : b;
    ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
    while (aPtr && bPtr) {
        if (aPtr->val < bPtr->val) {
            tail->next = aPtr; aPtr = aPtr->next;
        } else {
            tail->next = bPtr; bPtr = bPtr->next;
        }
        tail = tail->next;
    }
    tail->next = (aPtr ? aPtr : bPtr);
    return head.next;
}

// 优雅写法 归并
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode head = ListNode(), *now = &head;
        while (list1 && list2) {
            if(list1->val <= list2->val) {
                now->next = list1;
                list1 = list1->next;
            } else {
                now->next = list2;
                list2 = list2->next;
            }
            now = now->next;
        }
        now->next = list1 ? list1 : list2;
        return head.next;
    }
};