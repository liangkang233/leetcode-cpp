/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int find(int i) {
        if (parent[i] != i) //递归寻找root节点并把root赋值
            parent[i] = find(parent[i]);
        return parent[i];
    }
    void merge(int i, int j) {
        int root1 = find(i), root2 = find(j);
        if(root1 == root2)  // 若相等则两个集合有交集，相当于在同一个省份内的两个城市相连（成环）
            return;         // 这里不做任何处理 ans省份树不会减少
        ans--;  // 接下来进行合并
        if(rank[root1] >= rank[root2])
            parent[root2] = root1;
        else
            parent[root1] = root2;
        if (rank[root1] == rank[root2])
            rank[root1]++;
    }

    int ans;
    vector<int> parent, rank;

    int findCircleNum(vector<vector<int>>& isConnected) {
        ans = isConnected.size();   //初始视作每个城市都是一个省份
        rank.resize(ans, 0);
        for (int i = 0; i < isConnected.size(); i++)
            parent.push_back(i);
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected.size(); j++) {
                if (isConnected[i][j] == 0 || i == j)
                    continue;
                merge(i, j);
            }
        }
        return ans;
    }
};
// @lc code=end

