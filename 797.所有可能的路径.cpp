/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// dfs 回溯
class Solution {
public:
    vector<vector<int>> ans;
    void mydfs(vector<vector<int>>& graph, vector<int>& temp, int i) {
        if(i >= graph.size()-1) {
            ans.push_back(temp);
            return;
        }
        for (int j = 0; j < graph[i].size(); j++) {
            temp.push_back(graph[i][j]);
            mydfs(graph, temp, graph[i][j]);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp{0};
        mydfs(graph, temp, 0);
        return ans;
    }
};
// @lc code=end
// [[4,3,1],[3,2,4],[3],[4],[]]
// [[1],[]]


// 二刷
class Solution {
private:
    vector<vector<int>> ans;
public:
    void mydfs(vector<vector<int>>& graph, vector<int>& temp, int i) {
        temp.push_back(i);
        if(i == graph.size()-1) {
            ans.push_back(temp);
        } else {
            for (int j = 0; j < graph[i].size(); j++) {
                mydfs(graph, temp, graph[i][j]);
            }
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        // for (int i = 0; i < graph.size(); i++) {
        //     mydfs(graph, temp, i);
        // }
        mydfs(graph, temp, 0); // 只要0到n-1 节点的
        return ans;
    }
};