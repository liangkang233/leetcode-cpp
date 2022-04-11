/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// TODO


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
// bfs 减少 度为1 的节点
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> adjon(n);
        for (int i = 0; i < edges.size(); i++) {
            adjon[edges[i][0]].emplace_back(edges[i][1]);
            adjon[edges[i][1]].emplace_back(edges[i][0]);
        }
    }
};
// @lc code=end

// 使用dfs记录查询最长路径 随机选取1点p，找出p最长路径的终点x(有重复任取1点)，
// 以x为最长的路径的终点y(有重复任取1点)。最小高度树的根即为 xy 的中点 1 个 或 2 个。
// 由于结果在xy的路径中点，其结果一定在px路径路径上。
// 任取xy是可行的，若x不唯一，则x到p 与y到p长度相等
// 如果x唯一，则无论y是否唯一 其终点都在选择的xp中，y的选择不影响结果
// 如果x不唯一，则y的取值和x取值相同，取到中点即为p,xy任意选取不影响结果
class Solution {
public:
    void dfs(int u, vector<int> & dist, vector<int> & parent, const vector<vector<int>> & adj) {
        for (auto & v : adj[u]) {
            if (dist[v] < 0) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                dfs(v, dist, parent, adj); 
            }
        }
    }
    int findLongestNode(int u, vector<int> & parent, const vector<vector<int>> & adj) {
        int n = adj.size();
        vector<int> dist(n, -1); // dist 记录路径 长度  也能够标识是否到达过
        dist[u] = 0;
        dfs(u, dist, parent, adj);
        int maxdist = 0;
        int node = -1;
        for (int i = 0; i < n; i++) {
            if (dist[i] > maxdist) {
                maxdist = dist[i];
                node = i;
            }
        }
        return node;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<vector<int>> adj(n);
        for (auto & edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        vector<int> parent(n, -1);
        /* 找到距离节点 0 最远的节点  x */
        int x = findLongestNode(0, parent, adj); // 这一步的 parent 其实没有起到作用
        /* 找到距离节点 x 最远的节点  y */
        int y = findLongestNode(x, parent, adj); // parent 记录从x到y的路径
        /* 找到节点 x 到节点 y 的路径 */
        vector<int> path;
        parent[x] = -1;
        while (y != -1) {
            path.emplace_back(y);
            y = parent[y];
        }
        int m = path.size();
        if (m % 2 == 0) {
            return {path[m / 2 - 1], path[m / 2]};
        } else {
            return {path[m / 2]};
        }
    }
};