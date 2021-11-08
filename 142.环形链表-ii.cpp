/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

//  Definition for singly-linked list.
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 由141容易得到类似关系,看图即可
        // https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/
        // 2*(a+b) = a + n(b+c) + b;  所以相遇时再创建一个指针，相遇时即为所求位置
        // 注意，值题目没说不会相等，要用指针来做判断
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return nullptr;
        ListNode* A = head->next, *B = head->next->next;
        // while (A->val != B->val) {
        while (A != B) {
            if (B->next==nullptr || B->next->next==nullptr)
                return nullptr;
            // cout << A->val << " [1] " << B->val << endl;
            A=A->next;
            B=B->next->next;
        }
        A = head;
        // while (A->val != B->val) {
        while (A != B) {
            // cout << A->val << " [2] " << B->val << endl;
            A=A->next;
            B=B->next;
        }
        return A;
    }
};
// @lc code=end

//官方写的优雅多了
class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};