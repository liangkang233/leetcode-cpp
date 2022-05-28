/*
 * @lc app=leetcode.cn id=269 lang=cpp
 * 
 * [269] 火星字典  https://leetcode.cn/problems/alien-dictionary/
 * 
 * 剑指 Offer II 114. 外星文字典 https://leetcode.cn/problems/Jf1JuT/
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

// plus题
// 210 拓扑排序 进阶题
// 居然有 "abc" "ab" 这个案例 太坑了 还有 "z" z" 案例

class Solution {
private:
public:
    bool mydfs(vector<unordered_set<int>>& eadge, vector<int>& ms, string& ans, int i) {
        if(ms[i] == 1) // 出现环 必定无法推导正确方案
            return false;
        else if(ms[i] == 0 && !eadge[i].empty()) {
            ms[i] = 1;
            for (const int& e : eadge[i]) {                
                if(!mydfs(eadge, ms, ans, e)) // 仅有 edage[i][k] 相邻才进入递归
                    return false;
            }            
            ms[i] = 2;
            ans.push_back('a' + i);
        }
        return true;
    }
    string alienOrder(vector<string>& words) {
        string ans;
        vector<int> ms(26, -1); // -1 表示该字符不存在 0 表示未搜索 1 正在搜索 2 搜索完毕
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++)
                ms[words[i][j]-'a'] = 0;
        }
        vector<unordered_set<int>> eadge(26);
        // 字母相接表 eadge[i][j] 表示字母 i 要在 j 前面
        // 按照 特定字典序 排序 所以 在a的长度中 b 字符串必定大于等于 a 否则是无效串
        for (int i = 0; i < words.size()-1; i++) {
            for(int j = 0; j < words[i].size(); j++) {
                if(words[i][j] != words[i+1][j]) {
                    eadge[words[i][j]-'a'].insert(words[i+1][j]-'a');
                    break;
                }
                else if(j == words[i+1].size()-1 && words[i].size() > words[i+1].size()) { // 类似 "abc","ab" 这样的必定是无效的
                    return "";
                } 
            }
        }
        for (int i = 0; i < 26; i++){
            if(!mydfs(eadge, ms, ans, i))
                return "";
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < 26; i++){
            if(ms[i] == 0)
                ans.push_back('a' + i);
        }
        return ans;
    }
};

// 看官方的 上面的拓扑排序写的不好
