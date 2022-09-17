/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

#include <iostream>
#include <list>
using namespace std;

// @lc code=start
struct node {
    int val;
    node* last;
    node* next;
    node(int v, node* l, node* n): val(v), last(l), next(n) {}
};
class MyCircularDeque {
private:
    node* head;
    node* tail;
    int size;
    int maxn;
public:
    MyCircularDeque(int k): maxn(k), size(0), head(nullptr), tail(nullptr) {}
    
    bool insertFront(int value) {
        if(size == maxn) return false;
        head = new node(value, nullptr, head);
        if(head->next) head->next->last = head;
        size++;
        if(size == 1) tail = head;
        return true;
    }
    
    bool insertLast(int value) {
        if(size == maxn) return false;
        tail = new node(value, tail, nullptr);
        if(tail->last) tail->last->next=tail;
        size++;
        if(size == 1) head = tail;
        return true;
    }
    
    bool deleteFront() {
        if(size == 0) return false;
        size--;
        head = head->next;
        if(head) head->last = nullptr;
        // 提速 省去删除部分
        // node* temp = head; head = tail->next; delete(temp); if(head) head->last = nullptr;
        if(size == 0) tail = nullptr;
        return true;
    }
    
    bool deleteLast() {
        if(size == 0) return false;
        size--;
        tail = tail->last;
        if(tail) tail->next = nullptr;
        // 提速 省去删除部分
        // node* temp = tail; tail = tail->last; delete(temp); if(tail) tail->next = nullptr;
        if(size == 0) head = nullptr;
        return true;
    }
    
    int getFront() {
        if(!head) return -1;
        return head->val;
    }
    
    int getRear() {
        if(!tail) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == maxn;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

// ["MyCircularDeque","insertFront","getRear","insertFront","getRear","insertLast","getFront","getRear","getFront","insertLast","deleteLast","getFront"]\n[[3],[9],[],[9],[],[5],[],[],[],[8],[],[]]\n
// ["MyCircularDeque","insertFront","getFront","isEmpty","deleteFront","insertLast","getRear","insertLast","insertFront","deleteLast","insertLast","isEmpty"]\n[[8],[5],[],[],[],[3],[],[7],[7],[],[4],[]]
// ["MyCircularDeque","insertFront","getFront","insertFront","getFront","deleteLast","insertFront","insertFront","getRear","getFront","getRear","getRear","insertLast","deleteFront","getFront","insertLast","getRear","insertLast","deleteFront","insertFront","isFull","getRear","deleteLast","insertLast","getRear","getFront","getFront","insertLast","insertFront","deleteFront","getRear","insertLast","deleteFront","insertFront","insertFront","getRear","getFront","insertFront","insertLast","getRear","getFront","insertFront","insertFront","insertLast","insertLast","getRear","isEmpty","deleteFront","getRear","getRear","getRear","insertLast","getFront","getFront","deleteLast","deleteLast","insertLast","getRear","getRear","insertLast","insertLast","insertFront","getFront","getRear","getFront","insertFront","insertFront","deleteFront","isEmpty","getFront","deleteFront","isFull","getFront","getRear","insertLast","getFront","insertLast","getRear","insertLast","insertFront","getRear","getFront","getFront","deleteLast","deleteLast","insertLast","getRear","getRear","getFront","deleteLast","isFull","insertLast","insertLast","insertFront","getFront","insertFront","isFull","getRear","insertFront","deleteLast","insertLast","insertLast"]\n[[52],[80],[],[27],[],[],[60],[81],[],[],[],[],[46],[],[],[98],[],[11],[],[51],[],[],[],[28],[],[],[],[28],[69],[],[],[11],[],[25],[74],[],[],[48],[7],[],[],[65],[59],[23],[32],[],[],[],[],[],[],[84],[],[],[],[],[64],[],[],[17],[34],[46],[],[],[],[6],[20],[],[],[],[],[],[],[],[34],[],[66],[],[54],[34],[],[],[],[],[],[43],[],[],[],[],[],[21],[93],[79],[],[8],[],[],[78],[],[7],[67]]