/*
 * @lc app=leetcode.cn id=1455 lang=cpp
 *
 * [1455] 检查单词是否为句中其他单词的前缀
 */

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto isvaild = [&searchWord](const string& t) {
            if(t.size() < searchWord.size()) return false;
            for(int i = 0; i < searchWord.size(); i++) {
                if(searchWord[i] != t[i])
                    return false;
            }
            return true;
        };
        istringstream s(sentence);
        string t;
        for (int i = 1; s >> t; i++) {
            if (isvaild(t)) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

