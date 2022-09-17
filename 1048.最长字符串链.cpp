/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 *
 * [1048] 最长字符串链
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
private:
    typedef pair<string, int> pi; // 对应 该字符串 及 串联长度
public:
    bool isok(const string& a, const string& b) {
        int flag = 0;
        for (int i = 0, j = 0; i < a.size(); i++, j++) {
            if(a[i] != b[j]) {
                if(++flag > 1) return false;
                i--;
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int ans = 1;
        vector<vector<pi>> mp(17); // 根据长度 划分string
        for (int i = 0; i < words.size(); i++)
            mp[words[i].size()].push_back(pi{words[i], 1});
        for (int i = 1; i <= 16; i++) {
            for (int k = 0; k < mp[i].size(); k++) {
                for (int j = 0; j < mp[i-1].size(); j++) {
                    if( isok(mp[i-1][j].first, mp[i][k].first) ) {
                        mp[i][k].second = max(mp[i][k].second, mp[i-1][j].second + 1);
                        ans = max(mp[i][k].second, ans);
                    }
                }
                // cout << mp[i][k].first << ":" << mp[i][k].second << " ";
            } // cout << endl;
        }
        return ans;
    }
};
// @lc code=end
// ["a","b","ba","bca","bda","bdca"]\n["xbc","pcxbcf","xb","cxbc","pcxbc"]\n["abcd","dbqca"]\n["bdca","bda","ca","dca","a"]