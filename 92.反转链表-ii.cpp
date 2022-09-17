/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

#include <iostream>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode myhead = ListNode(-1, head);
        ListNode *LL, *RR, *L, *R, *now = &myhead, *last = nullptr;
        for(int i = 0; i <= right; i++) {
            if(i == left-1) LL = now;
            if(i == left) L = now;
            R = now;
            now = now->next;
        } RR = now;
        now = L;
        // cout << L->val << " " << R->val << endl;
        // cout << LL->val << " " << RR->val << endl;
        while (now != RR) {
            ListNode* temp = now->next;
            now->next = last;
            last = now;
            now = temp;
        }
        L->next = RR;
        LL->next = R;
        return myhead.next;
    }
};
// @lc code=end

