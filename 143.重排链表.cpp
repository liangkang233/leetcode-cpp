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

