/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
struct TrieNode {
    bool flag; // 为true 表示存在以该节点为尾部的值
    unordered_map<char, TrieNode*> son;
    TrieNode(): flag(false) {}
};
class Trie {
private:
TrieNode* root = nullptr;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* now = root;
        for (const char& w : word) {
            if(now->son.find(w) == now->son.end())
                now->son[w] = new TrieNode();
            now = now->son[w];
        }
        now->flag = true;
    }
    
    bool search(string word) {
        TrieNode* now = root;
        for (const char& w : word) {
            if(now->son.find(w) == now->son.end())
                return false;
            now = now->son[w];
        }
        return now->flag;
    }
    
    bool startsWith(string prefix) {
        TrieNode* now = root;
        for (const char& w : prefix) {
            if(now->son.find(w) == now->son.end())
                return false;
            now = now->son[w];
        }
        return now;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
// ["Trie","insert","search","search","startsWith","insert","search"]\n[[],["app"],["ap"],["app"],["app"],["apple"],["app"]]


// 官方字典树
class Trie {
private:
    vector<Trie*> children;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};
