/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU (least recently used) 缓存机制
 */

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// 使用map会更好改，但是题目要求时间O(1),用容器试试（测试失败）
// queue<int> myque; 用队列无法快速刷新，得不偿失 
// 最后方案按照答案用map存链表位置，双向链表来做缓存 （居然是自己实现的双向链表。。。 不是list）


// LK233 note 双向链表加一个伪头 伪尾，可以减少很多判断左右为空的操作 和 初始化赋值的操作
// @lc code=start


struct node {
    int key, value;
    node* pre;
    node* next;
    node(): key(0), value(0), pre(nullptr), next(nullptr) {}
    node(int a, int b, node* c, node *d): key(a), value(b), pre(c), next(d) {}

};// 设置链表头为旧缓存，链表尾为新缓存


class LRUCache {
public:
    int cap;
    // vector<node* > mymap;
    unordered_map<int, node*> cache;
    node *head , *tail ;

    void add_node(node* temp) {
        temp -> next = tail;
        temp -> pre = tail->pre;
        tail -> pre -> next = temp;
        tail -> pre = temp;
    }
    void remove_node(node* temp) {
        temp->pre->next = temp->next;
        temp->next->pre = temp->pre; 
    }
    void flush_node(node* temp) {
        remove_node(temp);
        add_node(temp);
    }

    LRUCache(int capacity): cap(capacity) {
        // mymap.resize(10001, nullptr);
        
        head = new node;
        tail = new node;
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        // 查找后只刷新缓存，不会添加删除缓存
        // if (mymap[key] != nullptr) {
        if ( cache.count(key) ) {
            // node* test = mymap[key];
            node* test = cache[key];
            flush_node(test);
            return test->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (get(key) == -1) {
            if (cap > 0)
                cap--;          
            else {
                // 删除缓存中最不常用的值
                node* test1 = head->next;
                remove_node(test1);
                // mymap[test1->key] = nullptr;
                cache.erase(test1->key);
                delete test1;
            }
            node* temp1 = new node(key, value, nullptr, nullptr);
            add_node(temp1);
            // mymap[key] = temp1;   
            cache.insert(make_pair(key, temp1));   
        }
        else {
            // get操作已经操作缓存,无需更新
            // node* test = mymap[key];
            node* test = cache[key];
            test->key = key;
            test->value = value;   
        }
    }


};

/**
 * 你的LRUCache对象将被实例化并像这样调用:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end