/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

// @lc code=start

// 直接用大数组或容器做map太占空间，做一个链表容器，官方答案是采用list 容器
class MyHashSet {
private:
    struct node {
        int val;
        node *next, *last;
        node(int a, node* b): val(a), last(b), next(nullptr) {}
    };
    vector<node *> mymap;
    const int base = 1024;
    int hash(int key) {
        return key % base;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() {
        mymap.assign(base, nullptr);
    }
    
    void add(int key) {
        int hash_key = hash(key);
        if (mymap[hash_key] == nullptr) {
            mymap[hash_key] = new node(key, nullptr);
            return;
        }

        node* temp = mymap[hash_key];
        while (1) {
            if (temp->val == key)
                return;
            if(temp -> next == nullptr)
                break;
            temp = temp->next;
        }
        temp->next = new node(key, temp); 
    }
    
    void remove(int key) {
        int hash_key = hash(key);
        node* temp = mymap[hash_key];
        for ( ; temp != nullptr; temp = temp->next) {
            if (temp->val == key) {
                if (temp->last == nullptr) { // 链表头
                    mymap[hash_key] = temp->next;
                    if (temp->next != nullptr)
                        temp->next->last = nullptr;
                }
                else if(temp->next == nullptr) {     // 链表尾
                    temp->last->next = nullptr;
                }
                else {
                    temp->last->next = temp->next;
                    temp->next->last = temp->last;
                }
                delete temp;
                return ;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hash_key = hash(key);
        node* temp = mymap[hash_key];
        for ( ; temp != nullptr; temp = temp->next) {
            if (temp->val == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

// 使用list容器，学习下
class MyHashSet1 {
private:
    vector<list<int>> data;
    static const int base = 769;
    static int hash(int key) {
        return key % base;
    }
public:
    /** Initialize your data structure here. */
    // MyHashSet1(): data(base) {}
    MyHashSet1(): data(base) {};
    
    void add(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) {
                return;
            }
        }
        data[h].push_back(key);
    }
    
    void remove(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) {
                data[h].erase(it);
                return;
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++) {
            if ((*it) == key) {
                return true;
            }
        }
        return false;
    }
};

