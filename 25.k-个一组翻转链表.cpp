/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
// 遍历翻转转
class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // tie(head, tail) = myReverse(head, tail); // 这里是 C++17 的写法，也可以写成
            pair<ListNode*, ListNode*> result = myReverse(head, tail);
            head = result.first;
            tail = result.second;
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};
// @lc code=end
// [1]\n1\n
// [1,1,2,3,4,5]\n1\n
// [1,1,2,3,4,5]\n2\n
// [1,1,2,3,4,5]\n6\n


// 最初方法 链表节点放入大小为k的栈中  空间复杂度O(k)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> st;
        ListNode* now = head, *ans = head, *rhead = nullptr, *rend = nullptr; // 记录这次遍历的k节点头 上次k节点的尾
        int count = k;
        while (now && k != 1) {
            count--;
            st.push(now);
            now = now->next;
            if (count == 0) {
                ListNode* temp;
                rhead = st.top();
                if(ans==head) ans = rhead; // 新链表即为第一个反转头
                while (!st.empty()) { // 逆序排列k个节点
                    temp = st.top();
                    st.pop();
                    if(!st.empty())
                        temp->next = st.top();
                    else
                        temp->next = now;
                }
                if(rend) // 存在上次的k个节点才进行 头尾相接
                    rend->next = rhead;
                rend = temp;
                count = k;
            }
        }
        return ans;
    }
};