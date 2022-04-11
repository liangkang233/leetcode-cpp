/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

#include <iostream>
#include <vector>
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

// 快慢指针找中点，后段链表反转后拼接。
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast=head, *slow=head;
        while (fast != nullptr) {   //快慢操作后，slow即为中点
            if(fast->next == nullptr)
                break;
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* rev=nullptr, *now=slow->next;
        slow->next=nullptr;
        while (now != nullptr) {  //反转中点节点后链表
            ListNode* temp = now->next;
            now->next=rev;
            rev = now;
            now = temp;
        }
        now=head;
        while (now != nullptr && rev != nullptr) { //拼接 rev head 两个链表
            ListNode* temp1 = now->next, * temp2 = rev->next;
            now->next = rev;
            rev->next = temp1;
            now = temp1;
            rev = temp2;
        }
    }
};
// @lc code=end

// 时间 空间复杂度为 O(N)
// 错误的 题目要求 不只是更改节点值 是进行节点交换
class Solution1 {
public:
    // 直接记录在数组中
    void reorderList(ListNode* head) {
        vector<ListNode*> s;
        ListNode* temp = head;
        while (temp != nullptr) {
            s.push_back(temp);
            temp = temp->next;
        }
        int i=0, j=s.size()-1;
        temp = head;
        while (i <= j) {
            // cout << s[i]->val << ", " << s[j]->val << endl;
            temp->next = s[i];
            s[i++]->next = s[j];
            temp = s[j--];
        }
        temp->next = nullptr;
    }
};


// 二刷
// 快慢指针 找到链表中点 反转后拼接
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head && head->next){
            ListNode* fast = head, *slow = head;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            } // slow 为中点 奇数个   偶数个为偏左中点
            fast = slow->next;
            slow->next = nullptr;
            // 反转链表
            ListNode* rHead = fast;
            while (fast->next) {
                ListNode* temp = fast->next->next;
                fast->next->next = rHead;
                rHead = fast->next;
                fast->next = temp;
            }
            // 拼接链表
            while (rHead) {
                ListNode* temp = head->next, *temp1 = rHead->next;
                head->next = rHead;
                rHead->next = temp;
                head = temp;
                rHead = temp1;
            }
        }
    }
};
