#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;


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


int main () {
    LRUCache sol(2);
    sol.put(1, 1); //缓存是{1=1}
    sol.put(2, 2); //缓存是{1=1, 2=2}
    sol.get(1);    //返回1
    sol.put(3, 3); //该操作会使得关键字2作废，缓存是{1=1, 3=3}
    sol.get(2);    //返回-1 (未找到)
    sol.put(4, 4); //该操作会使得关键字1作废，缓存是{4=4, 3=3}
    sol.get(1);    //返回-1 (未找到)
    sol.get(3);    //返回3
    sol.get(4);    //返回4

    return 0;
}