/* 面试题 01.09. 字符串轮转
字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。

示例1:
    输入：s1 = "waterbottle", s2 = "erbottlewat"
    输出：True
示例2:
    输入：s1 = "aa", s2 = "aba"
    输出：False
提示：
    字符串长度在[0, 100000]范围内。

你能只调用一次检查子串的方法吗？*/

#include <iostream>
#include <vector>
using namespace std;

// 直接暴力
class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1.size() == 0) return true;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            int j = 0;
            for(; j < n && s1[(i+j)%n] == s2[j]; j++) ;
            if(j == n) return true;
        }
        return false;
    }
};


// 利用kmp来做 在s1+s2 寻找 s2
class Solution {
public:
    int kmp(string s1, string s2) {
        vector<int> next(s2.size(), -1);
        for (int i = -1, j = 1; j < s2.size(); j++) {
            while (i != -1 && s2[i+1] != s2[j]) {
                i = next[i];
            }
            if(s2[j] == s2[i+1]) i++;
            next[j] = i;
        }
        for (int i = -1, j = 0; j < s1.size(); j++) {
            while (i != -1 && s2[i+1] != s1[j]) {
                i = next[i];
            }
            if(s1[j] == s2[i+1]) i++;
            if(i == s2.size()-1) return j - i;
        }
        return -1;
    }
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1.size() == 0) return true;
        if(kmp(s1+s1, s2) >= 0) return true;
        return false;
    }
};