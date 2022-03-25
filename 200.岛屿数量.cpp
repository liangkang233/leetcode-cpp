/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;


// @lc code=start
// bfs 效果不好
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        queue<array<int, 2>> myset;
        for (int i = 0; i < m; i++) {   // 先遍历找到1对其进行 广度搜索 记录
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    myset.push(array<int, 2>{i, j});
                    while (!myset.empty()) {
                        int x = myset.front()[0], y = myset.front()[1];
                        grid[x][y] = '2';    // 统计过的陆地记录为 2
                        myset.pop();

                        // !!! queue遍历到的坐标要提前标记 不要等到后续标记否则会重复遍历 超时
                        vector<array<int, 2>> index{{x-1,y},{x+1,y},{x,y-1},{x,y+1}};
                        for (int i = 0; i < index.size(); i++) {
                            if(index[i][0]>=0 && index[i][0]<m && index[i][1]>=0 && index[i][1]<n && grid[index[i][0]][index[i][1]]=='1') {
                                grid[index[i][0]][index[i][1]] = '2';
                                myset.push(array<int, 2>{index[i][0], index[i][1]});
                            }                            
                        }


                        // SB玩意 用for rangge会超时
                        // for (auto &&ind : index) {
                        //     if(ind[0]>=0 && ind[0]<m &&ind [1]>=0 && ind[1]<n && grid[ind[0]][ind[1]]=='1') {
                        //         grid[ind[0]][ind[0]] = '2';
                        //         myset.push(array<int, 2>{ind[0], ind[1]});
                        //     }
                        // }


                        // 用这个效果居然会缩减一半时间，从72ms 到 28ms 绝
                        // if(x-1 >= 0 && grid[x-1][y] == '1') {
                        //     grid[x-1][y] = '2';
                        //     myset.push(array<int, 2>{x-1, y});
                        // }
                        // if(x+1 < m && grid[x+1][y] == '1') {
                        //     grid[x+1][y] = '2';
                        //     myset.push(array<int, 2>{x+1, y});
                        // }
                        // if(y-1 >= 0 && grid[x][y-1] == '1') {
                        //     grid[x][y-1] = '2';
                        //     myset.push(array<int, 2>{x, y-1});
                        // }
                        // if(y+1 < n && grid[x][y+1] == '1') {
                        //     grid[x][y+1] = '2';
                        //     myset.push(array<int, 2>{x, y+1});
                        // }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
// [["1","0"]]\n
// [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","1","1","1"]]\n
// [["0","0","0","0","0"],["0","0","0","0","0"],["0","0","1","0","0"],["0","0","1","1","1"]]\n
// [["1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","0","1","0","1","1"],["0","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","0"],["1","0","1","1","1","0","0","1","1","0","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","0","0","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","0","1","1","1","1","1","1","0","1","1","1","0","1","1","1","0","1","1","1"],["0","1","1","1","1","1","1","1","1","1","1","1","0","1","1","0","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","0","1","1"],["1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["0","1","1","1","1","1","1","1","0","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","0","1","1","1","1","1","1","1","0","1","1","1","1","1","1"],["1","0","1","1","1","1","1","0","1","1","1","0","1","1","1","1","0","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","1","1","0"],["1","1","1","1","1","1","1","1","1","1","1","1","1","0","1","1","1","1","0","0"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1","1"]]




// 并查集 union-find
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * n + j);
                    ++count;
                }
                else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }

    int getCount() const {
        return count;
    }

private:
    vector<int> parent;
    vector<int> rank;
    int count;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        UnionFind uf(grid);
        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    grid[r][c] = '0';
                    if (r - 1 >= 0 && grid[r-1][c] == '1') uf.unite(r * nc + c, (r-1) * nc + c);
                    if (r + 1 < nr && grid[r+1][c] == '1') uf.unite(r * nc + c, (r+1) * nc + c);
                    if (c - 1 >= 0 && grid[r][c-1] == '1') uf.unite(r * nc + c, r * nc + c - 1);
                    if (c + 1 < nc && grid[r][c+1] == '1') uf.unite(r * nc + c, r * nc + c + 1);
                }
            }
        }

        return uf.getCount();
    }
};





// dfs 效果和bfs一样不好
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int nr = grid.size();
        int nc = grid[0].size();

        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();

        int num_islands = 0;
        for (int r = 0; r < nr; ++r) {
            for (int c = 0; c < nc; ++c) {
                if (grid[r][c] == '1') {
                    ++num_islands;
                    dfs(grid, r, c);
                }
            }
        }

        return num_islands;
    }
};