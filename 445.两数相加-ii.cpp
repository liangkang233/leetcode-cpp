/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    // 这里为了省空间直接 在原来的基础上改链表 写的不好没必要省
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> st, st1;
        ListNode* pL1 = l1, *pL2 = l2;
        int flag = 0, size1 = 0, size2 = 0;
        while(pL1) {
            st.push(pL1);
            pL1 = pL1->next;
            size1++;
        }
        while(pL2) {
            st1.push(pL2);
            pL2 = pL2->next;
            size2++;
        }
        if(size1 < size2) {
            ListNode* temp = l2;
            l2 = l1;
            l1 = temp;
            swap(st, st1);
        }
        ListNode* head = new ListNode(0, l1);
        while (flag || !st.empty()) {
            int val = 0;
            if(!st1.empty()) {
                val = st1.top()->val;
                st1.pop();
            }
            if(!st.empty()) {
                ListNode* temp = st.top();
                st.pop();
                temp->val += val + flag;
                flag = 0;
                if(temp->val > 9) {
                    flag = 1;
                    temp->val -= 10;
                }
            }
            else {
                head->val = flag;
                break;
            }
        }
        if(head->val == 0)
            head = head->next;
        return head;
    }
};
// @lc code=end
// [5]\n[5]\n
// [7,2,4,3]\n[5,6,4]
// [5,8,4]\n[2,4,7,8,9]\n

// 简洁的用string做
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a, b;
        ListNode *result = nullptr;
        while(l1) { a.push_back(l1->val+'0'); l1 = l1->next;}
        while(l2) { b.push_back(l2->val+'0'); l2 = l2->next;}
        int l = a.size()-1, r = b.size()-1, carry = 0;
        while(l >= 0 || r >= 0 || carry == 1) {
            int c = (l >= 0 ? a[l--]-'0' : 0) + ( r >= 0 ? b[r--]-'0' : 0) + carry;
            result = new ListNode(c%10, result);
            carry = c/10;
        }        
        return result;
    }
};

// 官方的栈
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int carry = 0;
        ListNode* ans = nullptr;
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            auto curnode = new ListNode(cur);
            curnode -> next = ans;
            ans = curnode;
        }
        return ans;
    }
};