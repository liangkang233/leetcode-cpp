/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <tuple>
using namespace std;



// @lc code=start
typedef pair<int, int> pi;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        vector<pi> mywords(words.size());
        for (int i = 0; i < words.size(); i++) {
            mywords[i].first = words[i].size();
            
            mywords[i].second = 0;
            for (int j = 0; j < words[i].size(); j++)
                mywords[i].second |= 1 << (words[i][j] - 'a');
        }
        for (int i = 0; i < mywords.size() - 1; i++) {
            for (int j = i+1; j < mywords.size(); j++) {
                if((mywords[i].second & mywords[j].second) == 0)
                    ans = max(mywords[i].first * mywords[j].first, ans);
            }
        }
        return ans;
    }
};
// @lc code=end

// ["a","ab","abc","d","cd","bcd","abcd"]
// ["a","aa","aaa","aaaa"]
// ["hj","ka","sd","hjkf","asdjkg","jkahsdk","gj","kasjhd","guhaj","k","weui","eyojnaejk","rghiawhfio","vjzdj","kg","hiuahuighakjg","huik","je"]\n


// 优化 采用unordered_map 优化掉 相同字母的字符 省去部分无效计算
// key 为 字母生成二进制串 value为其最大长度
class Solution {
public:
    int maxProduct (vector<string>& words) {
        int ans = 0;
        unordered_map<int, int> hash;        
        for (const string & word : words) {
            int mask = 0, size = word.size();
            for (const char& c : word) {
                mask |= 1 << (c-'a');
            }
            hash[mask] = max(hash[mask], size); // 不存在的key 调用[] 会初始化为0
            for (const auto& [h_mask, h_len] : hash) { // c++ 17 的写法 直接取出 pair 的值 并声明变量
                if (!(mask & h_mask))
                    ans = max(ans, size * h_len) ;
            }
        }
        return ans;
    }
};

// 二刷
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        unordered_map<int, int> mymap; // key为是否包含26个字符构成的数 对应该字符的最大长度
        for (int i = 0; i < words.size(); i++) {
            int temp = 0;
            for (int j = 0; j < words[i].size(); j++) {
                temp |= 1 << (words[i][j] - 'a');
            }
            mymap[temp] = max((int)words[i].size(), mymap[temp]);
        }
        for(auto it = mymap.begin(); it != mymap.end(); it++) {
            for (auto it1 = it; it1 != mymap.end(); it1++) {
                if((it->first & it1->first) == 0) // 注意 & 优先级 小于 ==
                    ans = max(ans, it->second * it1->second);
            }
        }
        return ans;
    }
};