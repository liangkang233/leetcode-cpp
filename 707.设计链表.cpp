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

// 单向链表的实现
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


struct ListNode1 {
    int val;
    ListNode1* next;
    ListNode1* pre;
    ListNode1(int n, ListNode1* p, ListNode1* q): val(n), pre(p), next(q) {}
};
// 双向链表的实现  太多细节要考虑了 折磨
class MyLinkedList {
private:
    ListNode1* myhead;  // 虚拟头
    ListNode1* tail;  // 链表尾
public:
    MyLinkedList() {
        myhead = new ListNode1(-1, nullptr, nullptr);
        tail = myhead;
    }
    
    int get(int index) {
        ListNode1* now = myhead;
        while (now && index >= 0) {
            // cout << now->val << " ";
            now = now->next;
            index--;
        }
        // cout << endl;
        return now ? now->val : -1;
    }
    
    void addAtHead(int val) {
        ListNode1* now = new ListNode1(val, myhead, myhead->next);
        if(myhead->next)
            myhead->next->pre = now;
        myhead->next = now;
        if(tail == myhead) tail = now; // 空链表时 添加头 也会更新尾部
    }
    
    void addAtTail(int val) {
        ListNode1* now = new ListNode1(val, tail, nullptr);
        tail->next = now;
        tail = now;
    };
    
    void addAtIndex(int index, int val) {
        ListNode1* now = myhead;
        while (now && index > 0) { // index <= 0 等价 index == 0  这里找的是index 下标前一位
            now = now->next;
            index--;
        }
        if(!now) return;
        ListNode1* add = new ListNode1(val, now, now->next);
        ListNode1* temp = now->next;
        now->next = add;
        if(temp)
            temp->pre = add;
        else 
            tail = add;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0) return;
        ListNode1* now = myhead;
        while (now && index >= 0) {
            // cout << now -> val << endl;
            now = now->next;
            index--;
        }
        if(!now) return;
        now->pre->next = now->next;
        if(now->next)
            now->next->pre = now->pre;
        else
            tail = now->pre;
    }
};