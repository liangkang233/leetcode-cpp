/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int n): val(n), next(nullptr) {}
    ListNode(int n, ListNode* link): val(0), next(link) {}
};
// @lc code=start

class MyLinkedList {
private:
    ListNode* myhead;
public:
    MyLinkedList() {
        myhead = new ListNode(0, nullptr);
    }
    
    int get(int index) {
        ListNode* now = myhead->next;
        for (int i = 0; i < index && now; i++)
            now = now->next;
        return !now ? -1 : now->val;
    }
    
    void addAtHead(int val) {
        ListNode* now = myhead->next;
        myhead->next = new ListNode(val, now);
    }
    
    void addAtTail(int val) {
        ListNode* now = myhead;
        while (now->next)
            now = now->next;
        now->next = new ListNode(val, nullptr);
    }
    
    void addAtIndex(int index, int val) {
        ListNode* now = myhead;
        while (now && index > 0) {
            now = now->next;
            index--;
        }
        if(now) // 防止超出下标 index 可以为 0 - n
            now->next = new ListNode(val, now->next);
    }
    
    void deleteAtIndex(int index) {
        ListNode* now = myhead;
        while (now && index > 0) {
            now = now->next;
            index--;
        }
        if(now && now->next) { // 取有效范围 index 可以为 0 - n-1
            // ListNode* temp = now->next;
            now->next = now->next->next;
            // delete temp;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

