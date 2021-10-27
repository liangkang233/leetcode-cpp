/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

#include <string>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    // 建立数组映射最快，且一定一一对应
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) 
            return false;
        char set1[127]{0}, set2[127]{0};
        for (int i = 0; i < s.size(); i++) {
            if(set1[s[i]] != set2[t[i]])
                return false;
            set1[s[i]] = set2[t[i]] = i+1; //防止set存入的新值与初始值0相同
        }
        return true;
    }
};
// @lc code=end

    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) 
            return false;
        unordered_map<char, char> mymap;
        for (int i=0; i < s.size(); i++) {
            if (mymap.find(t[i]) != mymap.end())
                return false;
            mymap.insert(make_pair(s[i], s[i]));
        }
        // 防止t的元素对应多个s的元素
        unordered_set<char> myset;
        for (auto &&info : mymap) {
            if (myset.find(info.second) != myset.end() )
                return false;
            myset.insert(info.second);
        }
        return true;
    }