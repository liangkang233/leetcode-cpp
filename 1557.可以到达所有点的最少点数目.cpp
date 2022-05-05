/*
 * @lc app=leetcode.cn id=1557 lang=cpp
 *
 * [1557] 可以到达所有点的最少点数目
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
//O(v+e) - need to check every edge and every vertex.
//O(n) space - need to keep in-degree for every node.
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
	// 如果有一条边到达某个顶点那么它可以从其他节点到达 
    // 但是如果一个顶点只有向外的边那么它就不能被其他顶点到达它必须是结果的一部分。
        vector<bool> conornot(n, false);   // 验证是否连接
        for(int i = 0; i < edges.size(); i++) 
            conornot[edges[i][1]] = true; // 值更新为一个表示其他顶点可以到达此顶点
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(!conornot[i])
                res.push_back(i); // 添加其他res中不可达的一个
        }
        return res;
    }
};

// @lc code=end
// 6\n[[0,1],[0,2],[2,5],[3,4],[2,4]]
// 6\n[[0,1],[0,2],[5,2],[3,4],[2,4]]
// 3\n[[0,1],[2,1]]

class Solution {
public:
    int find(vector<int>& father, int x) { //深度递归查找父节点 并更新途经父节点
        if(father[x] >= 0) {
            father[x] = find(father, father[x]);
            return father[x];
        }
        return x;
    }
    // 类似并查集确定父节点流程
    // 这种解法 解 [0,1][2,1] 也是正确的 毕竟 0 的确可由 1 或 2 达到 0的父节点只填0或1 最后计算得到的父节点 0 1 都存在不会少
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> myset;
        myset.insert(-1);
        vector<int> father(n, -1), ans; // 共有n个节点 -1 表示父节点为自己
        for (int i = 0; i < edges.size(); i++) // from 为父节点 to 为子节点
            father[edges[i][1]] = find(father, edges[i][0]);
        
        for (int i = 0; i < father.size(); i++) {
            int fa = i;
            if(father[fa] >= 0) // father[i] < 0 表示其是根节点 否则需要查询其深度最大父节点 并刷新根父节点
                fa = find(father, father[fa]);
            if(myset.find(fa) == myset.end()) {
                myset.insert(fa);
                ans.push_back(fa);
            }
        }
        return ans;
    }
};