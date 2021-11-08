/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    // 递归法 空间复杂度不仅为O(n) 而且不好理解，仅做参考
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr || head->next==nullptr)
            return head;
        ListNode* rev = reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return rev;
    }
};
// @lc code=end

    // 迭代法 空间复杂度O(n) 时间复杂度O(1)
    ListNode* reverseList(ListNode* head) {
        ListNode* rev = nullptr;
        while (head != nullptr) {
            ListNode* temp = head->next;
            head->next = rev;
            rev = head;
            head = temp;
        }
        return rev;
    }
