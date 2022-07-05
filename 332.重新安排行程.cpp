/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool mydfs(unordered_map<string, map<string, int>>& mp, vector<string>& ans, string t, int N) {
        if(ans.size() == N+1)  return true;
        if(mp.find(t) != mp.end()) {
            auto & m = mp[t];
            for (auto & i : m) {
                if(i.second > 0) {
                    i.second--;
                    ans.push_back(i.first);
                    if(mydfs(mp, ans, i.first, N))
                        return true;
                    i.second++;
                    ans.pop_back();
                }
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, map<string, int>> mp; // map默认按照字典序排序  mp记录 所有边相邻边的次数
        for (int i = 0; i < tickets.size(); i++)
            mp[tickets[i][0]][tickets[i][1]]++;
        vector<string> ans{"JFK"};
        /*for (auto && i : mp) {
            cout << i.first << ": ";
            for(auto && j : i.second) {
                cout << j.first << " " << j.second << ", ";
            }
            cout << endl;
        } */
        mydfs(mp, ans, "JFK", tickets.size());
        return ans;
    }
};
// @lc code=end
// [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
// [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]