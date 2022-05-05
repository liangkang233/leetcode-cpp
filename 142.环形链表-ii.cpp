/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// Definition for singly-linked list.
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int a) : val(a), next(nullptr) {}
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

// https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/
// 下面为不完备证明  完整的还是看官方
// slow: i = a + b + k(b+c)   => 2i = 2x + 2b + 2k(b+c)
// fast: 2i = a + b + n(b+c)
// 上式子相减 0 = a + b + (2k-n)(b+c) => a = c + (n-2k-1)(b+c)
// 此时 让 fast 节点回到初始位置, slow 不变 继续两个节点同时步进1位 重合时即为答案



// 计算过程: 设重合处 需要经历 a 步 坐标为 a-1，尾部经历 n 步 坐标 n-1
// 在第i步重合 fast slow指针 此时 fast 经过 2i 步， slow 经过 i 步。
// 2i = (n+1) + (i-a)  =>  a = n+1- i
// 此时 让 fast 节点回到初始位置, slow 不变 继续两个节点同时步进1位
// 当 fast = a 时， slow = i+a = n+1 也到达重合点x 即为输出答案
// 二刷
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head) {
            int index = 0;
            ListNode * fast = head, *slow = head;
            while(fast->next && fast->next->next) {
                fast=fast->next->next;
                slow = slow->next;
                if(slow == fast) {
                    ListNode *fast = head;
                    while (fast != slow) {
                        fast = fast->next;
                        slow = slow->next;
                    }
                    return fast;
                }
            }
        }
        return nullptr;
    }
};
