/*
 * @lc app=leetcode.cn id=1568 lang=cpp
 *
 * [1568] 使陆地分离的最少天数
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 脑筋急转弯 https://leetcode-cn.com/problems/minimum-number-of-days-to-disconnect-island/solution/shi-lu-di-fen-chi-de-zui-shao-tian-shu-by-leetcode/
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void dfs(int x, int y, vector<vector<int>>& grid, int n, int m) {
        grid[x][y] = 2; //dfs遍历过标记
        for (int i = 0; i < 4; ++i) { //对应 grid[x][y] 上下左右四个方向
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || grid[tx][ty] != 1) {
                continue;
            }
            dfs(tx, ty, grid, n, m);
        }
    }
    int count(vector<vector<int>>& grid, int n, int m) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    cnt++;
                    dfs(i, j, grid, n, m);
                }
            }
        }
        // 还原
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        // 岛屿数量不为 1，陆地已经分离
        if (count(grid, n, m) != 1) {
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    if (count(grid, n, m) != 1) {
                        // 更改一个陆地单元为水单元后陆地分离
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
// @lc code=end
