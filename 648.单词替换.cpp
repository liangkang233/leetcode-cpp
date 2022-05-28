/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// @lc code=start
struct TrieNode {   // 全为小写字母用 vector 代替 map
    bool end;       // 为true 表示存在以该节点为尾部的值
    vector<TrieNode*> son;
    TrieNode(): end(false), son(26) {}
};

class Solution {
private:
    TrieNode* root;
public:
    Solution() { root = new TrieNode();}
    // ~Solution() { // 后序dfs free 省略来提速
    //     DeleteRoot(root);
    // }
    // void DeleteRoot(TrieNode *pRoot) { // 根据根节点删除整棵树
    //     if(pRoot) {
    //         for (int i = 0; i < pRoot->son.size(); i++)
    //             DeleteRoot(pRoot->son[i]);
    //         delete pRoot;
    //     }
    // }
    string replaceWords(vector<string>& dictionary, string sentence) {
        istringstream sen(sentence);
        string in, out, ans;
        for (int i = 0; i < dictionary.size(); i++) { // 建树
            TrieNode* now = root;
            for (char& c : dictionary[i]) {
                if(!now->son[c-'a'])
                    now->son[c-'a'] = new TrieNode();
                now = now->son[c-'a'];
            }
            now->end = true;
        }
        while (sen >> in) { // 以最小前缀匹配树
            TrieNode* now = root;
            for (char& c : in) {
                // cout << c << " ";
                if(!now->son[c-'a']) {
                    out = in;
                    break;
                }  
                now = now->son[c-'a'];
                out.push_back(c);
                if(now->end)
                    break;
            }
            // cout << out << endl;
            ans += out + " ";
            out.clear();
        }
        ans.pop_back();
        return ans;
    }
};
// @lc code=end

