/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

// 把题目示例看懂就好
// @lc code=start
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int L = 0, R = 0, add = 0, temp = 0;
        ListNode* head = new ListNode(0), *last = head;
        while ( l1 || l2 || add) {
            L = l1 ? l1->val : 0;
            R = l2 ? l2->val : 0;
            temp = L + R +add;

            if(temp >= 10) {
                last-> next = new ListNode(temp - 10);
                add = 1; 
            }
            else {
                last-> next = new ListNode(temp);
                add = 0;
            }
            last = last -> next;
            if(l1)  l1 = l1->next;
            if(l2)  l2 = l2->next;
        }
        return head->next;
    }
};
// @lc code=end

// 二刷 直接在l1上操作 省时间和空间
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = l1;
        for (int flag = 0; flag || l1 || l2; ) {
            int temp1 = 0, temp2 = 0;
            if(l1) temp1 = l1->val;
            if(l2) temp2 = l2->val;
            l1->val = flag + temp1 + temp2;
            if(l1->val >= 10) {
                flag = 1;
                l1->val -= 10;
            } else
                flag = 0;
            if(l2)  l2 = l2->next;
            if (!l1->next && (flag || l2))
                l1->next = new ListNode(0, nullptr);
            if(l1)  l1 = l1->next;
        }
        return ans;
    }
};