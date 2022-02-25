/*
 * @lc app=leetcode.cn id=1791 lang=cpp
 *
 * [1791] 找出星型图的中心节点
 */

#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int> myset;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                auto test = myset.insert(edges[i][j]);
                if(!test.second)
                    return edges[i][j];
            }
        }
        return -1;
    }
};
// @lc code=end

// 一行搞定
// return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
