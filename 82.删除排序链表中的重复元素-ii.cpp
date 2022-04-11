/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
        ListNode vhead(INT_MIN, head), *temp = &vhead; // 构建虚拟头
        for (ListNode* i = head; i != nullptr; ) {
            if(i->next != nullptr && i->val == i->next->val) { // 删除重复指针
                int X = i->val;
                while (i != nullptr && i->val == X) {
                    temp->next = i->next;
                    delete(i);
                    i = temp->next;
                }
                i = temp->next;
            }
            else {
                temp = i;
                i = temp->next;
            } 
        }
        return vhead.next;
    }
};
// @lc code=end
// [1,1,1,2,3]\n
// []\n
// [1]\n

// 二刷 加了delete 就很慢  刷题不考虑内存泄漏也太 👶🌶
// @lc code=start
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode myhead = ListNode(-1, head), *temp = &myhead; // 不需要new一个对象
        while (temp && temp->next) {
            if(temp->next->next && temp->next->next->val == temp->next->val) {
                int val = temp->next->val;
                while(temp->next && temp->next->val == val) {
                    ListNode* del = temp->next; 
                    temp->next = temp->next->next;
                    delete del;
                }
                continue;
            }
            temp = temp->next;
        }
        return myhead.next;
    }
};