/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
private:
    typedef pair<string, double> pi;
    unordered_map<string, vector<pi>> mp; // 字串对应的 下一跳 indedx
public:
    bool mydfs(unordered_set<string>& ms, string s, string e, double& val) {
        if(mp.find(s) != mp.end() && ms.find(s)==ms.end()) {
            // cout << s << endl;
            if(s == e)
                return true;
            ms.insert(s);
            vector<pi>& v = mp[s];
            for (int i = 0; i < v.size(); i++) {
                val *= v[i].second;
                if(mydfs(ms, v[i].first, e, val))
                    return true;
                val /= v[i].second;
            }
            ms.erase(s);
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans(queries.size(), 1.0);
        for (int i = 0; i < equations.size(); i++) {
            mp[equations[i][0]].push_back(pi{equations[i][1], values[i]});
            if(values[i] != 0)
                mp[equations[i][1]].push_back(pi{equations[i][0], 1/values[i]});
        }
        // for (auto & i : mp) {
        //     cout << i.first << ": ";
        //     for (auto& j : i.second){
        //         cout << j.first << " " << j.second << " ";
        //     } cout << endl;
        // }
        
        for (int i = 0; i < queries.size(); i++) {
            unordered_set<string> ms;
            // mydfs 找不到直接 return-1 可能会和中间值-1冲突导致无法return
            if(mp.find(queries[i][1]) == mp.end() || !mydfs(ms, queries[i][0], queries[i][1], ans[i]))
                ans[i] = -1.0;
            // cout << ans[i] << endl;
        }
        return ans;
    }
};
// @lc code=end
// [["a","b"],["b","c"],["bc","cd"]]\n[1.5,2.5,5.0]\n[["a","c"],["c","b"],["bc","cd"],["cd","bc"]]\n
// [["a","b"]]\n[0.5]\n[["a","b"],["b","a"],["a","c"],["x","y"]]\n
