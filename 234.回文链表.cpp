/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

#include <iostream>
#include <stack>
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
    ListNode* myreverse(ListNode* head) { // 翻转链表 模板
        ListNode* rhead = nullptr;
        while (head) {
            ListNode* temp = head->next;
            head->next = rhead;
            rhead = head;
            head = temp;
        }
        return rhead;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head) {
            ListNode* fast = head, *slow = head, * temp;
            while (fast->next && fast->next->next) {
                fast = fast->next->next;
                slow = slow->next;
            } // slow 节点偶数为中点左边 单数为中点
            temp = slow->next;
            slow->next = nullptr; // 注意需要断开 虽然此处不影响结果
            fast = myreverse(temp);
            slow = head;
            while (fast) {
                cout << slow->val << " " << fast->val << endl;
                if(slow->val != fast->val)
                    return false;
                slow = slow->next;
                fast = fast->next;
            }
        }
        return true;
    }
};
// @lc code=end
// [1,2,3,2,1]\n


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> st;
        ListNode* fast = head, *slow = head;
        int size = 0;
        while (fast) {
            fast = fast->next;
            size++;
            if(fast) {
                st.push(slow);
                fast = fast->next;
                slow = slow->next;
                size++;
            }
        } // slow 节点偶数为中点右边 单数为中点
        if(size % 2)
            slow = slow->next;
        while (!st.empty()) {
            if(st.top()->val != slow->val)
                return false;
            slow = slow->next;
            st.pop();
        }
        return true;
    }
};
