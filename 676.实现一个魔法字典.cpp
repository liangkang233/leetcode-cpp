/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
struct TrieNode {   // 全为小写字母用 vector 代替 map
    bool end;       // 为true 表示存在以该节点为尾部的值
    vector<TrieNode*> son;
    TrieNode(): end(false), son(26) {}
};

class MagicDictionary {
private:
    TrieNode* root;
public:
    MagicDictionary() {root = new TrieNode();}
    // ~MagicDictionary() { // 后序dfs free 这里省略来提速
    //     DeleteRoot(root);
    // }
    // void DeleteRoot(TrieNode *pRoot) { // 根据根节点删除整棵树
    //     if(pRoot) {
    //         for (int i = 0; i < pRoot->son.size(); i++)
    //             DeleteRoot(pRoot->son[i]);
    //         delete pRoot;
    //     }
    // }
    void buildDict(vector<string> dictionary) {
        for (int i = 0; i < dictionary.size(); i++) {
            TrieNode* now = root;
            for (char& c : dictionary[i]) {
                if(!now->son[c-'a'])
                    now->son[c-'a'] = new TrieNode();
                now = now->son[c-'a'];
            }
            now->end = true;
        }
    }
    
    bool find(string word, TrieNode* node, int count) {
        if (word.empty())
            return node->end && count == 1;
        if (count > 1)   return false;
        string chs = word.substr(1, word.size() - 1);
        for (int i = 0; i < 26; i++) {
            int next = count;
            if (!node->son[i])   continue;
            if (word.front() - 'a' != i) next++;
            if (find(chs, node->son[i], next))
                return true;
        }
        return false;
    }
    bool search(string searchWord) {
        return find(searchWord, root, 0);
    }
};
/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end
// ["MagicDictionary", "buildDict", "search", "search", "search", "search"]\n[[], [["hello","leetcode"]], ["hello"], ["hhllo"], ["helllq"], ["helloq"]]


// 二刷
struct trienode{
    vector<trienode*> son;
    bool end;
    trienode(): end(false), son(26) {}
};

class MagicDictionary {
private:
    trienode* root;
public:
    MagicDictionary() {
        root = new trienode();
    }
    
    void buildDict(vector<string> dictionary) {
        for (int i = 0; i < dictionary.size(); i++) {
            trienode* now = root;
            for (const char& t : dictionary[i]) {
                if(!now->son[t-'a'])
                    now->son[t-'a'] = new trienode();
                now = now->son[t-'a'];
            } now->end = true;
        }
    }
    bool mysearch(const string& s, trienode* now, int index, int change) {
        if(change > 1) return false;
        if(index == s.size())
            return change == 1 && now->end;
        int N = s[index] - 'a';
        for (int j = 0; j < 26; j++) {
            int c = change + (j != N ? 1 : 0);
            if(now->son[j] && mysearch(s, now->son[j], index+1, c))
                return true;
        }
        return false;
    }
    
    bool search(string searchWord) {
        return mysearch(searchWord, root, 0, 0);
    }
};