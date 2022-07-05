/*
 * @lc app=leetcode.cn id=2257 lang=cpp
 *
 * [2257] 统计网格图中没有被保卫的格子数
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// @lc code=start

// 直接dfs 每个节点四个方向暴力扫  遇到警卫或墙停止 ()
class Solution {
private:
    int ans;
public:
    void mydfs(vector<vector<int>>& record, int x, int y, int m, int n) {
        for (int i = y+1; i < n; i++) {
            if(record[x][i] == 0) {
                record[x][i] = 1;
                ans--;
            } else if(record[x][i] == 2 || record[x][i] == 3) {
                break;
            }
        }
        for (int i = y-1; i >= 0 && record[x][i]!=3; i--) {
            if(record[x][i] == 0) {
                record[x][i] = 1;
                ans--;
            } else if(record[x][i] == 2 || record[x][i] == 3) {
                break;
            }
        }
        for (int i = x+1; i < m && record[i][y]!=3; i++) {
            if(record[i][y] == 0) {
                record[i][y] = 1;
                ans--;
            } else if(record[i][y] == 2 || record[i][y] == 3) {
                break;
            }
        }
        for (int i = x-1; i >= 0 && record[i][y]!=3; i--) {
            if(record[i][y] == 0) {
                record[i][y] = 1;
                ans--;
            } else if(record[i][y] == 2 || record[i][y] == 3) {
                break;
            }
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        ans = m * n - guards.size() - walls.size();
        vector<vector<int>> record(m, vector<int>(n, 0));
        for (int i = 0; i < guards.size(); i++) record[guards[i][0]][guards[i][1]]=2;
        for (int i = 0; i < walls.size(); i++) record[walls[i][0]][walls[i][1]]=3;
        for (int i = 0; i < guards.size(); i++) mydfs(record, guards[i][0], guards[i][1], m, n);
        return ans;
    }
};
// @lc code=end
// 3\n3\n[[1,1]]\n[[0,1],[1,0],[2,1],[1,2]]\n

// 广度优先搜索 + 存储每个格子的状态
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n));   // 网格状态数组
        queue<tuple<int, int, int>> q;   // 广度优先搜索队列
        // 每个方向的单位向量
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        for (const auto& guard: guards) {
            grid[guard[0]][guard[1]] = -1;
            for (int k = 0; k < 4; ++k) {
                // 将四个方向视线对应的状态均添加进搜索队列中
                q.emplace(guard[0], guard[1], k);
            }
        }
        for (const auto& wall: walls) {
            grid[wall[0]][wall[1]] = -2;
        }
        while (!q.empty()) {
            auto [x, y, k] = q.front();
            q.pop();
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] >= 0) {
                // 沿着视线方向的下一个坐标合法，且不为警卫或墙
                if ((grid[nx][ny] & (1 << k)) == 0) {
                    // 对应状态未遍历过 1 << k 代表四种状态
                    grid[nx][ny] |= (1 << k);
                    q.emplace(nx, ny, k);
                }
            }
        }
        int res = 0;   // 未被保护格子数目
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++res;
                }
            }
        }
        return res;
    }
};