/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

#include<unordered_set>
#include<iostream>
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
    // 常规方法使用栈 只扫描一次的方法: 使用快慢指针找到中点 计算长度
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode myhead = ListNode(-1, head), *slow = head, *fast = head; // 虚拟头
        int size = 0;
        while (fast) {
            fast = fast->next;
            size++;
            if(fast) {
                fast = fast->next;
                size++;
                slow = slow->next;
            }
        }
        n = size - n; // n 为 需要删除的下标
        fast = slow;
        if(n <= size/2)
            fast = &myhead;
        else
            n -= size / 2 + 1;
        // cout << n << " fast-val: " << fast->val << " " << size;         
        while (n-- > 0)
            fast = fast->next;
        fast->next = fast->next->next;
        return myhead.next;
    }
};
// @lc code=end
// [1,2]\n1
// [1,2,3,4,5]\n5
// [1,2,3,4,5,6]\n6
// [1,2,3,4,5,6]\n1
// [1,2,3]\n1


// 看看官方写的 清爽的很
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};