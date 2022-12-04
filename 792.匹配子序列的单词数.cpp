/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


// @lc code=start
class Solution {
private:
    unordered_map<char, vector<int>> record;
public:
    bool myfun(const string& s, const string& word) {
        if(word.size() > s.size()) return false;
        int index = -1;
        for (int i = 0; i < word.size(); i++) {
            // 新下标必须要在老下标的后面 使用 upper_bound 二分查
            auto it = upper_bound(record[word[i]].begin(), record[word[i]].end(), index);
            if(it == record[word[i]].end())
                return false;
            index = *it;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            record[s[i]].push_back(i);
        }
        for(auto& word : words) {
            if(myfun(s, word))
                ans++;
        }
        return ans;
    }
};
// @lc code=end

// "dsahjpjauf"\n["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]\n

// 分桶来做 妙啊
// string copy的开销比较大， 所以buckets中保存的是pair<int, int>, 
// 分别是单词在wrods中的索引， 和该单词下一个要处理的字母在该单词中的索引。
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<queue<pair<int, int>>> buckets(26);
        for(int i = 0; i < words.size(); i++){
            buckets[words[i][0]-'a'].push({i, 0});
        }
        int res = 0;
        for(auto c: S){
            queue<pair<int, int>> & q = buckets[c-'a'];
            for(int i = q.size(); i > 0; i--){
                auto [wordIndex, posIndex] = q.front();
                q.pop();
                posIndex++;
                if(posIndex == words[wordIndex].length()){
                    res++;
                }
                else{
                    buckets[words[wordIndex][posIndex] - 'a'].push({wordIndex, posIndex});
                }
            }
        }
        return res;
    }
};
