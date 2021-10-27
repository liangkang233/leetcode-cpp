/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */

#include<iostream>
#include <string>
#include <algorithm>
#include <stringstream>
using namespace std;


// 此题没啥好说的，让我想到一道经典的题，反转字符串
// 例如：i tell you 变为 you tell i
// 解法就是每个字符串反转，之后总字符串反转
// @lc code=start
class Solution {
public:
    void myrever (string& s, int l, int r) {
        char temp;
        while (l < r) {
            temp = s[l];
            s[l++] = s[r];
            s[r--] = temp;
        }
    }
    string reverseWords(string s) {
        int l = 0, r = 0;
        for (int i = 0; i < s.length(); i++) {
            if(s.at(i) == ' ') {
                l = r;
                myrever(s, l, i-1);
                r = i + 1;
            }
        }
        myrever(s, r, s.length()-1);
        return s;
    }
};
// @lc code=end

// 用容器做的，效率低些
class Solution1 {
public:
    string reverseWords(string s) {
        string res="";
        string tmp="";
        stringstream ss(s);
        if(s.empty()) return res;
        while(ss>>tmp){
            reverse(tmp.begin(),tmp.end());
            res+=tmp+' ';
        }
        res.pop_back();
        return res;
    }
};
