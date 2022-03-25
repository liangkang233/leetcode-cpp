/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

#include <iostream>
#include <vector>
#include <queue>
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
            for (int j = 0; j <= i; j++) {
                if (isConnected[i][j] == 0 || i == j)
                    continue;
                merge(i, j);
            }
        }
        return ans;
    }
};
// @lc code=end

// DFS 做法 由题意 二维数组关于 x=y 对称
// 没有剪枝 做个visited 效果差  看看官方的dfs后修改
class Solution {
public:
    void mydfs(int i, vector<vector<int>>& isConnected, vector<int>& visited) {
        for (int k = 0; k < isConnected.size(); k++) { // 查询所有与i相关的
            if(!visited[k] && isConnected[i][k]) {
                visited[k] = 1;
                mydfs(k, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        vector<int> visited(isConnected.size(), 0);
        for (int i = 0; i < isConnected.size(); i++) {
            if(!visited[i]) {
                visited[i] = 1;
                // for (int j = 0; j < isConnected.size(); j++) {
                //     if(isConnected[i][j] && !visited[j]) {
                //         visited[j]=1;
                //         mydfs(j, isConnected, visited);
                //     }
                // }
                mydfs(i, isConnected, visited);
                ans++;
            }
        }
        return ans;
    }
};
// [[1,0,0],[0,1,0],[0,0,1]]\n


// bfs做法
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = isConnected.size();
        vector<int> visited(provinces);
        int circles = 0;
        queue<int> Q;
        for (int i = 0; i < provinces; i++) {
            if (!visited[i]) {
                Q.push(i);
                while (!Q.empty()) {
                    int j = Q.front(); Q.pop();
                    visited[j] = 1;
                    for (int k = 0; k < provinces; k++) {
                        if (isConnected[j][k] == 1 && !visited[k]) {
                            Q.push(k);
                        }
                    }
                }
                circles++;
            }
        }
        return circles;
    }
};