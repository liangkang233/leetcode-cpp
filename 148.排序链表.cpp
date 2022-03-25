/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head != nullptr && head->next != nullptr) {
            ListNode *fast = head, *slow = head;
            while (fast->next != nullptr) { // find mid
                fast = fast->next;            
                if (fast->next != nullptr) {
                    fast = fast->next;            
                    slow = slow->next;
                }
            }

            fast = sortList(slow->next);
            slow->next = nullptr;
            head = sortList(head);
            vector<ListNode*> temp;
            while(head!=nullptr && fast!=nullptr) { // merge
                if(head->val <= fast->val) {
                    temp.push_back(head);
                    head = head->next;
                }else {
                    temp.push_back(fast);
                    fast = fast->next;
                }
            }
            while (head!=nullptr) {
                temp.push_back(head);
                head = head->next;
            }
            while (fast!=nullptr) {
                temp.push_back(fast);
                fast = fast->next;
            }
            temp.back()->next = nullptr;
            for (int i = 0; i < temp.size() - 1; i++)
                temp[i]->next = temp[i+1];
            head = temp[0];
        }
        return head;
    }
};
// @lc code=end
// []\n
// [1]\n
// [10,4]\n
// [-1,5,3,4,0]\n



// 官方题解 自底向上 归并 只需要 O(1) 空间复杂度  起始就是 递归改成遍历
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};
