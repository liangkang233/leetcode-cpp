/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// @lc code=start
// 优化下原代码
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> myque;
        unordered_set<string> ms(wordList.begin(), wordList.end()), ms1;
        int depth = 1;
        myque.push(beginWord);
        while (!myque.empty()) {
            int size = myque.size();
            for (int i = 0; i < size; i++) {
                string t = myque.front();
                myque.pop();
                // cout << t << " ";
                if(t == endWord)
                    return depth;
                for (int j = 0; j < t.size(); j++) {
                    string s = t;
                    for (int k = 0; k < 26; k++) {
                        s[j] = k + 'a';
                        if(ms.find(s) != ms.end() && ms1.find(s) == ms1.end()) { // 一个需要包含 一个为去重
                            myque.push(s);
                            ms1.insert(s);
                        }
                    }
                }
            }
            // cout << "depth:" << depth << endl;
            depth++;
        }
        return 0;
    }
};
// @lc code=end
// "hit"\n"cog"\n["hot","dot","dog","lot","log"]


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> myque;
        unordered_set<string> ms(wordList.begin(), wordList.end()), ms1;
        if(ms.find(endWord) != ms.end()) { // end 必须包含
            myque.push(beginWord);
            ms.insert(beginWord); // 防止 wordList 第一次查询不到该数据
        }
        int depth = 1;
        while (!myque.empty()) {
            int size = myque.size();
            for (int i = 0; i < size; i++) {
                string t = myque.front();
                myque.pop();
                if(t == endWord)
                    return depth;
                if(ms.find(t) != ms.end() && ms1.find(t) == ms1.end()) { // 一个需要包含 一个为去重
                    ms1.insert(t);
                    // cout << t << " ";
                    for (int j = 0; j < t.size(); j++) {
                        string s = t;
                        for (int k = 0; k < 26; k++) {
                            s[j] = k + 'a';
                            myque.push(s);
                        }
                    }
                }
            }
            // cout << "depth:" << depth << endl;
            depth++;
        }
        return 0;
    }
};