/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head, *slow=head;
        while (fast != nullptr) {
            if (fast->next == nullptr)
                return slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};
// @lc code=end

