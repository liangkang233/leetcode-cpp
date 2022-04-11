/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// 关键点在于删除栈N次后，依旧能快速读出当前栈状态的最小值

// 法1 使用单向链表做自定义的栈
// @lc code=start
class MinStack {
private:
    struct node {
        int min, val;
        // node* pre;
        node* next;
        node(): min(0), val(0), next(nullptr) {}
        node(int a, int b, node *d): val(a), min(b), next(d) {}
    };

public:
    node* head = nullptr;

    MinStack() {
        node* head = new node();
    }
    
    void push(int val) {
        if (head == nullptr)
            head = new node(val, val, nullptr);
        else 
            head = new node(val, min(val,head->min), head);
    }
    
    void pop() {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
    }
};
/**
 * 你的MinStack对象将被实例化并被这样调用:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end


// 法2 使用辅助栈（官方），同步当前栈最小值状态
// 感觉投机取巧了
class MinStack1 {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack1() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

// 二刷
struct Node {        // 构建辅助的单向链表
    int val, minVal; // 当前指针的值 以及链表头到当前尾部的最小值
    Node* last;
    Node(int a, int b, Node* c): val(a), minVal(b), last(c) {}
};

class MinStack {
public:
    Node* tail;
    MinStack() {
        tail = nullptr;
    }
    
    void push(int val) {
        if(!tail)
            tail = new Node(val, val, nullptr);
        else
            tail = new Node(val, min(val, tail->minVal), tail);
    }
    
    void pop() {
        if(tail) {
            Node* temp = tail;
            tail = tail->last;
            delete temp;
        }
    }
    
    int top() {
        if(tail)
            return tail->val;
        else 
            return -1;
    }
    
    int getMin() {
        if(tail)
            return tail->minVal;
        else 
            return -1;
    }
};