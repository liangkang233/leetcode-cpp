/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()) return arr;
        vector<int> ans(arr);
        unordered_map<int, int> mp;
        sort(arr.begin(), arr.end());
        mp[arr[0]] = 1;
        for (int i = 1, j = 1; i < arr.size(); i++) {
            if(arr[i] > arr[i-1])
                mp[arr[i]] = ++j;
        }
        for(int i = 0; i < arr.size(); i++)
            ans[i] = mp[ans[i]];
        return ans;
    }
};
// @lc code=end