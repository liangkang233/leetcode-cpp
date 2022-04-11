/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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
    ListNode* swapPairs(ListNode* head) {
        ListNode myhead = ListNode(-1, head), *now = &myhead;
        while (now->next && now->next->next) {
            ListNode* temp1 = now->next;
            now->next = temp1->next;
            temp1->next = now->next->next;
            now->next->next = temp1;
            now = temp1;
        }
        return myhead.next;
    }
};
// @lc code=end
// [1,24,5,6,8,7,5,6,8,34,86,23,56,67,5,67,6]\n
