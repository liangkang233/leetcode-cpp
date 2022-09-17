/*
 * @lc app=leetcode.cn id=1408 lang=cpp
 *
 * [1408] 数组中的字符串匹配
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) { // words 没有 重复单词
        unordered_set<string> ms(words.begin(), words.end()), ms1;
        vector<string> ans;
        for(int i = 0; i < words.size(); i++) {
            for(int len = 1; len < words[i].size(); len++) {
                for (int j = 0; j + len <= words[i].size(); j++) {
                    string a = words[i].substr(j, len);
                    // cout << a << endl;
                    if(ms.find(a) != ms.end())
                        ms1.insert(a);
                }
            }
        }
        for(auto& ii : ms1)
            ans.push_back(ii);
        return ans;
    }
};
// @lc code=end

