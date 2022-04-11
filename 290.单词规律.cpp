/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> S;
        int i = 0, j = 0;
        for (; j < s.size(); j++) {
            if(s[j] != ' ')
                continue;
            S.push_back(s.substr(i, j-i));
            i = j+1;
        }
        S.push_back(s.substr(i, j-i)); // s数组切割预处理
        
        if(pattern.size() != S.size())
            return false;
        unordered_map<char, string> mymap;
        for (int i = 0; i < pattern.size(); i++) {
            if(mymap.find(pattern[i]) == mymap.end())
                mymap.insert(make_pair(pattern[i], S[i]));
            else if(mymap[pattern[i]] != S[i])
                return false;
        }
        // 验证是否一一对应
        unordered_set<string> myset;
        for (auto &&[ch, str] : mymap) {
            if(myset.find(str) != myset.end())
                return false;
            myset.insert(str);
        }
                
        return true;
    }
};
// @lc code=end
// ""abba"\n"asdijfij""
// ""abc"\n"as as as""
// ""abb"\n"as ass asss""
// ""abc"\n"as ass asss""

// 二刷 官方是采用两个hash表， 我这里还是用一个map 一个set
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map <char, string> mymap;
        int i = 0, start = 0, end = 0;
        for (; i < pattern.size() && end < s.size(); i++) {
            while (end < s.size() && s[end] != ' ') end++;
            // cout << start << " " << end-start << endl;
            string temp = s.substr(start, end-start);
            // cout << temp << endl;
            end++;
            start = end;
            if(mymap.find(pattern[i]) == mymap.end())
                mymap.insert(make_pair(pattern[i], temp));
            else if(mymap[pattern[i]] != temp)
                return false;
        }
        if(end < s.size() || i < pattern.size())
            return false;
        unordered_set <string> myset;
        // for (unordered_map <char, string>::iterator it = mymap.begin(); it != mymap.end(); it++) {
        for (auto it = mymap.begin(); it != mymap.end(); it++) {
            if(myset.find(it->second) != myset.end())
                return false;
            myset.insert(it->second);
        }
        return true;
    }
};
// ""abba"\n"asdijfij""
// ""a"\n"asd ijf ij""
// ""abc"\n"as as as""
// ""abb"\n"as ass asss""
// ""abc"\n"as ass asss""