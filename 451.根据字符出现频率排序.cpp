/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    typedef pair<char,int> mypair;

    string frequencySort(string s) {
        unordered_map<char, int> mymap;
        vector<mypair> myarray;
        auto mygreater = [](mypair a, mypair b) -> bool {return a.second > b.second;};
        for(auto c : s) 
            mymap[c]++;
        for (auto &it : mymap)
            myarray.emplace_back(it);
        sort(myarray.begin(), myarray.end(), mygreater);
        string ans;
        for(auto&[c,num] : myarray) {
            // cout << c << " " << num << endl;
            for (int i = 0; i < num; i++)
                ans.push_back(c);
        }
        return ans;
    }
};
// @lc code=end

// 桶排序也是很不错的
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        int maxFreq = 0;
        int length = s.size();
        for (auto &ch : s) {
            maxFreq = max(maxFreq, ++mp[ch]);
        }
        vector<string> buckets(maxFreq + 1);
        for (auto &[ch, num] : mp) {
            buckets[num].push_back(ch);
        }
        string ret;
        for (int i = maxFreq; i > 0; i--) {
            string &bucket = buckets[i];
            for (auto &ch : bucket) {
                for (int k = 0; k < i; k++) {
                    ret.push_back(ch);
                }
            }
        }
        return ret;
    }
};


// 二刷 使用堆 不如用sort
typedef pair<char,int> mypair;
class mycmp {
public:
    bool operator() (const mypair& a, const mypair& b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mymap;
        priority_queue<mypair, vector<mypair>, mycmp>myque;
        for (int i = 0; i < s.size(); i++)
            mymap[s[i]]++;
        for (auto &&pi : mymap)
            myque.emplace(pi);
        string ans;
        while(!myque.empty()) {
            ans.append(myque.top().second, myque.top().first);
            myque.pop();
        }
        return ans;
    }
};