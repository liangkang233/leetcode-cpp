/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> myworddict(wordDict.begin(), wordDict.end());
        myworddict.insert("");
        vector<int> dp(s.size(), false); // dp[i] 代表下标 0-i 是否成立可由表达
        for (int i = 0; i < s.size(); i++) {
            for(int j = 0; j <= i; j++) {
                if((j==0 || dp[j-1]) && myworddict.find(s.substr(j, i-j+1)) != myworddict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};
// @lc code=end
// "catsandog"\n["cats","dog", "sand", "and", "cat"]\n
// "catsaasdfakgjkljalksdjgandog"\n["caa","dasdgg", "s", "asdg", "tuio"]\n

// 【优化】对于以上代码可以优化。每次并不需要从s[0]开始搜索。因为wordDict中的字符串长度是有限的。
// 只需要从i-maxWordLength开始搜索就可以了。
bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1, false);
    unordered_set<string> m;
    dp[0] = true;
    int maxWordLength = 0;    //获取最长字符串长度
    for (int i = 0; i < wordDict.size(); ++i){
        m.insert(wordDict[i]);
        maxWordLength = std::max(maxWordLength, (int)wordDict[i].size());
    }
    for (int i = 1; i <= s.size(); ++i){
        for (int j = std::max(i-maxWordLength, 0); j < i; ++j){
            if (dp[j] && m.find(s.substr(j, i-j)) != m.end()){
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}


// 用kmp做的话，例如s中为”abca“，给出字典中有 "a" 重复情况难做，感觉效果也不是很好。  放弃！
class Solution {
public:
    pair<int, int> kmp(string& s, string& word) {
        int len = word.size(), slen = s.size();
        vector<int> next(len, -1);
        if(slen >= len) {
            for (int i = -1, j = 1; j < len; j++) {
                while (i!=-1 && s[i+1] != s[j])
                    i = next[i];
                if(s[i+1] == s[j])
                    i++;
                next[j] = i;
            }
            for (int i = -1, j = 0; j < slen; j++) {
                while (i != -1 && word[i+1] != s[j])
                    i = next[i];
                if(word[i+1] == s[j])
                    i++;
                if(i == len-1)
                    return make_pair(j-i, j);
            }
        }
        return make_pair(-1, -1);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<pair<int, int>> dictmap;
        for (int i = 0; i < wordDict.size(); i++) {
            pair<int, int> index = kmp(s, wordDict[i]);
            cout << index.first << " " << index.second << endl;
            if(index.first != -1)
                dictmap.push_back(index);
        }
        return true;
    }
};