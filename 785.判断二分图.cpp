/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
private:
    unordered_set<int> myset, myset1;
public:
    bool mydfs(vector<vector<int>>& graph, int i) {
        if(graph[i].size() == 0) // 独立的空节点 跳过
            return true;
        bool flag = false;
        if(myset.find(i) != myset.end())
            flag = true;
        for (int j = 0; j < graph[i].size(); j++) {
            if(flag) { // 相邻元素不能出现在 myset 中
                if(myset1.find(graph[i][j]) != myset1.end())
                    continue;
                myset1.insert(graph[i][j]);
                if(myset.find(graph[i][j]) != myset.end() || !mydfs(graph, graph[i][j]))
                    return false;
            } else { // 相邻元素不能出现在 myset1 中
                myset.insert(graph[i][j]);
                if(myset1.find(graph[i][j]) != myset1.end() || !mydfs(graph, graph[i][j]))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        for (int i = 0; i < graph.size(); i++) {
            if(myset.find(i)==myset.end() && myset1.find(i)==myset1.end()) {
                myset.insert(i);
                if(!mydfs(graph, i))
                    return false;
            }
        }
        return true;
        // myset.insert(0);
        // return mydfs(graph, 0);
    }
};
// @lc code=end
// [[],[3],[],[1],[]]
// [[],[2,4,6],[1,4,8,9],[7,8],[1,2,8,9],[6,9],[1,5,7,8,9],[3,6,9],[2,3,4,6,9],[2,4,5,6,7,8]]
// [[2,4],[2,3,4],[0,1],[1],[0,1],[7],[9],[5],[],[6],[12,14],[],[10],[],[10],[19],[18],[],[16],[15],[23],[23],[],[20,21],[],[],[27],[26],[],[],[34],[33,34],[],[31],[30,31],[38,39],[37,38,39],[36],[35,36],[35,36],[43],[],[],[40],[],[49],[47,48,49],[46,48,49],[46,47,49],[45,46,47,48]]