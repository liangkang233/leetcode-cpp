/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = nullptr;
        for (ListNode* i = head; i != nullptr; i = i->next) {
            if(temp != nullptr && i->val == temp->val) { // 删除重复指针
                temp->next = i->next;
                delete(i);
                i = temp;
            }
            temp = i;
        }
        return head;
    }
};
// @lc code=end

	

