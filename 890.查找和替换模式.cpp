/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    //其实用数组就可以做到一一对应
    bool match(const string word, const string pattern) {
        int set1[127] = {0}, set2[127] = {0};
        for (int i = 0; i < word.size(); i++) {
            if (set1[word[i]] != set2[pattern[i]])
                return false;
            set1[word[i]] = set2[pattern[i]] = i+1; //防止和默认初始值0相同
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto&& word : words) {
            if(match(word, pattern))
                ans.push_back(word);
        }
        return ans;
    }
};
// @lc code=end


    // 做映射表，如果同一字母映射个数大于1(已经有映射了)，说明有1对多现象 非一一对应
    bool match(const string word, const string pattern) {
        unordered_map<char, char> mymap;
        for (int i = 0; i < word.size(); i++) {
            if(mymap.find(pattern[i]) != mymap.end()) {
                if(mymap[pattern[i]] != word[i])
                    return false;
            }else {
                mymap.insert(make_pair(pattern[i], word[i]));
            }
        }
        // 做映射判断是否一一对应，如果有一对多的false
        unordered_set<char> myset;
        for (auto&& info : mymap) {
            if(myset.find(info.second) != myset.end())
                return false;
            myset.insert(info.second);
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto&& word : words) {
            if(match(word, pattern))
                ans.push_back(word);
        }
        return ans;
    }

// 二刷
class Solution {
public:
    bool match(const string& a, const string& b) {
        if(a.size() != b.size())
            return false;
        int s1[128] = {0}, s2[128] = {0};
        for (int i = 0; i < a.size(); i++) {
            if(s1[a[i]] == 0 && s2[b[i]] == 0) {
                s1[a[i]] = b[i];
                s2[b[i]] = a[i];
            }
            else if(s1[a[i]] != b[i] || s2[b[i]] != a[i])
                return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            if(match(words[i], pattern))
                ans.push_back(words[i]);
        }
        return ans;
    }
};