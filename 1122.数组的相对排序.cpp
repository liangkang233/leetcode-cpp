/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
// 做法很多 sort定义排序规则 应该效率最高
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> mymap;
        for (int i = 0; i < arr2.size(); i++) {
            mymap[arr2[i]] = i;
        }        
        auto mycmp = [&mymap](int a, int b) -> bool {
            int val_l = 10000 + a, val_r = 10000 + b; // 最大个数1000 将不存在的权值加上10000
            if (mymap.find(a) != mymap.end())
                val_l = mymap[a];
            if (mymap.find(b) != mymap.end())
                val_r = mymap[b];
            return val_l < val_r;
        };
        sort(arr1.begin(), arr1.end(), mycmp);
        return arr1;
    }
};
// @lc code=end
// [28,6,22,8,44,17]\n[22,28,8,6]