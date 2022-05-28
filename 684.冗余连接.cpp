/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// 并查集 基础应用 删去最后出现的边 即为 第一个且唯一一个导致出现环的边
// 由题意 导致出现环的边 仅仅一个 找到直接return
class Solution {
public:
    int find(vector<int>& fa, int i) {
        if(fa[i] != -1) {
            fa[i] = find(fa, fa[i]);
            return fa[i];
        } return i;
    }
    bool merge(vector<int>& fa, vector<int>& dep, int x, int y) {
        int rx = find(fa, x), ry = find(fa, y);
        // cout << rx << " " << ry << endl;
        if(rx == ry)
            return false;
        if(dep[rx] < dep[ry])
            swap(rx, ry);
        else if(dep[rx] == dep[ry])
            dep[rx]+=1;
        fa[ry] = rx;
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> fa(edges.size()+1, -1), dep(edges.size()+1, 0);
        for (int i = 0; i < edges.size(); i++) {
            if(!merge(fa, dep, edges[i][0], edges[i][1]))
                return edges[i];
        }
        return vector<int> {};
    }
};
// @lc code=end
