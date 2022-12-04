/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// 必须使用哈希表记录克隆无向表的连接 否则会陷入死循环  用unordered_set会使得双向图 变为 单向图
// @lc code=start
class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node) {return nullptr;}
        if(mp.find(node) != mp.end()) return mp[node];
        Node* now = new Node(node->val);
        mp[node] = now; // 防止递归回来
        for(int i = 0; i < node->neighbors.size(); i++) {
            now->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return now;
    }
};
// @lc code=end

// 会造成死循环
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) {return nullptr;}
        Node* now = new Node(node->val);
        for(int i = 0; i < node->neighbors.size(); i++) {
            now->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return now;
    }
};