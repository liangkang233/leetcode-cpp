/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

// 翻译题意即为找出所有后缀相同 在助记串s 中将其归并在一个后缀相同的最长单词中
// @lc code=start
class tireNode {
public:
    vector<tireNode*> son;
    tireNode(): son(26) {}
};

class Solution {
public:
    void add(tireNode* root, string word) {
        tireNode* now = root;
        for (int i = word.size() - 1; i >= 0; i--) {
            if(!now->son[word[i] - 'a'])
                now->son[word[i] - 'a'] = new tireNode();
            now = now->son[word[i] - 'a'];
        }
    }
    int search(tireNode* root, int depth) {
        int sum = 0;
        for (int i = 0; i < root->son.size(); i++) {
            if(root->son[i]) // 只计算子树不为空的分支的值
                sum += search(root->son[i], depth + 1);
        }
        return sum==0 ? depth : sum; // sum为0 则子树全为空 该节点就是一个最长前缀时
    }
    int minimumLengthEncoding(vector<string>& words) {
        tireNode* root = new tireNode();
        for (string & word : words)
            add(root, word);
        return search(root, 1); // 每一个字符串都加上一个 '#'
    }
};
// @lc code=end

// 直接 哈希表 效果不错 写的也轻松
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> good(words.begin(), words.end());
        for (const string& word: words) {
            for (int k = 1; k < word.size(); ++k) {
                good.erase(word.substr(k));
            }
        }

        int ans = 0;
        for (const string& word: good) {
            ans += word.size() + 1;
        }
        return ans;
    }
};