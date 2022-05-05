/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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

// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode-solutio-a8jn/
// @lc code=start
class Solution {
public:
    // 空间O(1) 时间O(m+n)的方法:
    // 使用 双指针 某一指针遍历完后 更新到另一个链表 不断进行对比判断
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA && headB) {
            ListNode* temp1 = headA, *temp2 = headB;
            while (temp1 || temp2) { // 同时为空 遍历完毕 不存在相同值
                if(!temp1)  temp1 = headB;
                if(!temp2)  temp2 = headA;
                if(temp1 == temp2)  return temp1;
                // cout << temp1->val << " " << temp2->val << endl;
                temp1=temp1->next;
                temp2=temp2->next;
            }            
        }
        return nullptr;
    }
};
// @lc code=end

// 0\n[1,2,3,4]\n[1,2,3,4]\n12\n12
// 3\n[3]\n[2,3]\n0\n1

class Solution {
public:
    // 最简单的做法 B链表里的指针存到set中 或者存入栈内 再遍历一遍A对比
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp = headB;
        unordered_set<ListNode*> myset;
        while (temp) {
            myset.insert(temp);
            temp = temp->next;
        }
        temp = headA;
        while (temp) {
            if(myset.find(temp) != myset.end())
                return temp;
            temp=temp->next;
        }
        return nullptr;
    }
};

// 二刷
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA, *tempB = headB;
        bool flag = true;
        while (tempA != tempB) {
            if(!tempA)
                tempA = headB;
            else
                tempA = tempA->next;
            if(!tempB)
                tempB = headA;
            else
                tempB = tempB->next;
        } // 同时为空 说明两链表无接触
        return tempA ? tempA : nullptr;
    }
};