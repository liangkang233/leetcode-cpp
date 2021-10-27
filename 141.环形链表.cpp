/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) 
            return false;
        ListNode *A = head->next, *B = head->next->next;
        while (B != A) {
            // if (A->next == nullptr) 
            //     return false;
            A = A->next;
            if (B->next == nullptr || B->next->next == nullptr)
                return false;
            B = B->next->next;
        }
        return true;
    }
};
// @lc code=end

