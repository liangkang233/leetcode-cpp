/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

#include <iostream>
#include <algorithm>
#include <list>
#include <set>
#include <unordered_map>
using namespace std;

// 双哈希表
// @lc code=start
struct node {
    int cnt, key, value;
    node(int _key, int _value, int _cnt): key(_key), value(_value), cnt(_cnt) {}
};
class LFUCache {
private:
    int cap, minF = 0;
    list<node> li;                                // li 是根据 使用顺序 排列的链表
    unordered_map<int, list<node>> M;             // M 记录 该频率 对应的 list
    unordered_map<int, list<node>::iterator> mp;  // mp 记录 key 对应 list 元素 指针
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        int value = mp[key]->value, cnt = mp[key]->cnt;
        M[cnt].erase(mp[key]); // 删除节点  且该链表为空时 更新 minF 最小频率
        if(M[cnt].empty() && minF == cnt)
            minF = cnt+1;
        M[cnt+1].push_back(node{key, value, cnt+1}); // 添加对应频率节点
        mp[key] = prev(M[cnt+1].end());              // 更新 mp[key]
        return value;
    }
    void put(int key, int value) {
        if(cap == 0) return; // 注意这里 cap 居然可以为 0
        if(get(key) < 0) {   // 一定要 先删再插 否则会修改 minF 导致错误
            if(mp.size() == cap) {
                int temp = M[minF].front().key;
                mp.erase(temp);
                M[minF].pop_front();
            }
            minF = 1;
            M[1].push_back(node{key, value, 1});
            mp[key] = prev(M[1].end());
        } else {
            mp[key]->value = value;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



// 使用 set 模拟平衡二叉树  直接用 set 排序对应 cnt time   插入 时间复杂度 为 log n
struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}
    
    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};
class LFUCache {
    int capacity, time; // 缓存容量，时间戳
    unordered_map<int, Node> key_table;
    set<Node> S;
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }
    
    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        // 如果哈希表中没有键 key，返回 -1
        if (it == key_table.end()) return -1;
        // 从哈希表中得到旧的缓存
        Node cache = it -> second;
        // 从平衡二叉树中删除旧的缓存
        S.erase(cache);
        // 将旧缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        // 将新缓存重新放入哈希表和平衡二叉树中
        S.insert(cache);
        it -> second = cache;
        return cache.value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 如果到达缓存容量上限
            if (key_table.size() == capacity) {
                // 从哈希表和平衡二叉树中删除最近最少使用的缓存
                key_table.erase(S.begin() -> key);
                S.erase(S.begin());
            }
            // 创建新的缓存
            Node cache = Node(1, ++time, key, value);
            // 将新缓存放入哈希表和平衡二叉树中
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        }
        else {
            // 这里和 get() 函数类似
            Node cache = it -> second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value;
            S.insert(cache);
            it -> second = cache;
        }
    }
};