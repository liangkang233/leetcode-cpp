/*
 * @lc app=leetcode.cn id=1282 lang=cpp
 *
 * [1282] 用户分组
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < groupSizes.size(); i++) {
            mp[groupSizes[i]].push_back(i);
        }
        for (auto& ii : mp) {
            for(int j = 0; j < ii.second.size(); ) {
                vector<int> temp;
                for(int k = j; j-k < ii.first; j++) {
                    temp.push_back(ii.second[j]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
// @lc code=end

