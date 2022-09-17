/*
 * @lc app=leetcode.cn id=745 lang=cpp
 *
 * [745] 前缀和后缀搜索
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


// @lc code=start
class WordFilter {
private:
unordered_map<string, int> mp;
public:
    WordFilter(vector<string>& words) {
        for(int i = words.size()-1; i >= 0; i--) {
            for(int j = 0; j < words[i].size(); j++) {
                string temp = words[i].substr(0, j+1);
                for(int k = words[i].size()-1; k >=0; k--) {
                    string t = temp + " " + words[i].substr(k, words[i].size()-k);
                    if(mp.find(t) == mp.end()) {
                        mp[t] = i;
                    }
                }
            }
        }
    }
    int f(string pref, string suff) {
        string ans = pref + " " + suff;
        if(mp.find(ans) == mp.end())
        mp[ans] = -1;
        return mp[ans]; 
    }
};  

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
// @lc code=end

// 官方 字典树 
struct Trie {
    unordered_map<string, Trie *> children;
    int weight;
};

class WordFilter {
private:
    Trie *trie;

public:
    WordFilter(vector<string>& words) {
        trie = new Trie();
        for (int i = 0; i < words.size(); i++) { // 下标(权重)逐渐变大 后面遍历时权重会替换掉之前的
            string word = words[i];
            Trie *cur = trie;
            int m = word.size();
            for (int j = 0; j < m; j++) {
                Trie *tmp = cur;
                for (int k = j; k < m; k++) { // 后缀不够长的情况 使用for 遍历完之后的全部情况
                    string key({word[k], '#'});
                    if (!tmp->children.count(key)) {
                        tmp->children[key] = new Trie();
                    }
                    tmp = tmp->children[key];
                    tmp->weight = i;
                }
                tmp = cur;
                for (int k = j; k < m; k++) { // 前缀不够长的情况 使用for 遍历完之后的全部情况
                    string key({'#', word[m - k - 1]});
                    if (!tmp->children.count(key)) {
                        tmp->children[key] = new Trie();
                    }
                    tmp = tmp->children[key];
                    tmp->weight = i;
                }
                string key({word[j], word[m - j - 1]}); // 一般情况下匹配前后缀
                if (!cur->children.count(key)) {
                    cur->children[key] = new Trie();
                }
                cur = cur->children[key];
                cur->weight = i;
            }
        }
    }
    
    int f(string pref, string suff) {
        Trie *cur = trie;
        int m = max(pref.size(), suff.size());
        for (int i = 0; i < m; i++) {
            char c1 = i < pref.size() ? pref[i] : '#';
            char c2 = i < suff.size() ? suff[suff.size() - 1 - i] : '#';
            string key({c1, c2});
            if (!cur->children.count(key)) {
                return -1;
            }
            cur = cur->children[key];
        }
        return cur->weight;
    }
};
