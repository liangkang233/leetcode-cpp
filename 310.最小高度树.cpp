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
#include <queue>
using namespace std;

// @lc code=start
// bfs 减少 度为1 的节点  拓扑排序法
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return vector<int>{0};
        vector<vector<int>> adjon(n);
        vector<int> record(n), ans;
        for (int i = 0; i < edges.size(); i++) {
            adjon[edges[i][0]].emplace_back(edges[i][1]);
            adjon[edges[i][1]].emplace_back(edges[i][0]);
            record[edges[i][0]]++;
            record[edges[i][1]]++;
        }
        queue<int> nodeque;
        for (int i = 0; i < n; i++) {
            if(record[i] == 1) nodeque.push(i);
        }
        // while (nodeque.size() > 2) { // 只对size()判断不一定正确，例如nodeque一开始就是2的情况 邻居表[[0,1],[0,2]]
        while (n > 2) { // bfs 减少度为1 的节点
            int len = nodeque.size();
            for (int i = 0; i < len; i++) {
                int now = nodeque.front();
                nodeque.pop();
                record[now] = 0;
                n--;
                for (int j = 0; j < adjon[now].size(); j++) {
                    if(--record[adjon[now][j]] == 1)
                        nodeque.push(adjon[now][j]);
                } // 下面的写法更好看些 上面朴素的写法省些空间
                // for(auto && node : adjon[now]) {
                //     if(--record[node] == 1)
                //         nodeque.push(node);
                // }
            }
        }
        while (!nodeque.empty()) {
            ans.push_back(nodeque.front());
            nodeque.pop();
        }
        return ans;
    }
};
// @lc code=end
// 6\n[[3,0],[3,1],[3,2],[3,4],[5,4]]
// 3\n[[0,1],[0,2]]
// 2\n[[0,1]]


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