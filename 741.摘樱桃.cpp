/*
 * @lc app=leetcode.cn id=741 lang=cpp
 *
 * [741] 摘樱桃
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
// 返回的操作可以视为 再从 0,0 到 N-1,N-1 走一遍  需要考虑所有路径不可贪心 例如第一次取最大值 不一定代表走两次为最大值
// 再压缩下时间复杂度 改为两人同时走 而不是 走完一圈后再递归     注意 需要使用记忆化搜索 map
// 两个人同时走 都向右下角走 除非当前格子相同 必定不会出现A出现B之前走过的位置 也就不用考虑复杂的回溯了
class Solution {
private:
unordered_map<int, int> mp;
public:
    int mydfs(int x, int y, int x1, int y1, vector<vector<int>>& grid) {
        int index = x * 1000000 + y * 10000 + x1 * 100 + y1, ans = -1, path = 0;
        if(mp.find(index) != mp.end())  return mp[index];
        auto isok = [&grid](int x, int y) {
            return x < grid.size() && y < grid.size() && grid[x][y] >= 0;};
        if(grid[x][y] == 1) path++; // A B 两轮重合只加一次
        if(grid[x1][y1] == 1 && x1 != x && y1 != y) path++;
        if(x == grid.size()-1 && y == x) { // A到达终点 B必定也到达终点
            return path;
        } else {
            if(isok(x+1, y) && isok(x1+1, y1)) {
                ans = max(mydfs(x+1, y, x1+1, y1, grid), ans);
            } if(isok(x+1, y) && isok(x1, y1+1)) {
                ans = max(mydfs(x+1, y, x1, y1+1, grid), ans);
                mydfs(x+1, y, x1, y1+1, grid);
            } if(isok(x, y+1) && isok(x1+1, y1)) {
                ans = max(mydfs(x, y+1, x1+1, y1, grid), ans);
            } if(isok(x, y+1) && isok(x1, y1+1)) {
                ans = max(mydfs(x, y+1, x1, y1+1, grid), ans);
            }
        }
        if(ans >= 0) ans += path; // 有出路 才加上当前值   否则为-1
        mp[index] = ans;
        return ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        return max(mydfs(0, 0, 0, 0, grid), 0);
    }
};
// @lc code=end
// [[1,1,1],[1,1,1],[1,1,1]]
// [[1,1,1,1,0,0,0],[0,0,0,1,0,0,0],[0,0,0,1,0,0,1],[1,0,0,1,0,0,0],[0,0,0,1,0,0,0],[0,0,0,1,0,0,0],[0,0,0,1,1,1,1]]
// [[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1],[0,0,0,1,0,0,0,0,0,0,1,1,1,1]]


// 官解的动规 定义 f[k][x1][x2] 表示两个人(设为A和B)分别从(x1, k-x1)和(x2, k-x2)同时出发，
// 到达(N-1, N-1)摘到的樱桃个数之和的最大值。   f[k][x1][x2] 为 -1 表示该路径不可到达
class Solution {
public:
    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<vector<int>>> f(n * 2 - 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int x1 = max(k - n + 1, 0); x1 <= min(k, n - 1); ++x1) {
                int y1 = k - x1;
                if (grid[x1][y1] == -1) {
                    continue;
                }
                for (int x2 = x1; x2 <= min(k, n - 1); ++x2) {
                    int y2 = k - x2;
                    if (grid[x2][y2] == -1) {
                        continue;
                    }
                    int res = f[k - 1][x1][x2]; // 都往右
                    if (x1) {
                        res = max(res, f[k - 1][x1 - 1][x2]); // 往下，往右
                    }
                    if (x2) {
                        res = max(res, f[k - 1][x1][x2 - 1]); // 往右，往下
                    }
                    if (x1 && x2) {
                        res = max(res, f[k - 1][x1 - 1][x2 - 1]); // 都往下
                    }
                    res += grid[x1][y1];
                    if (x2 != x1) { // 避免重复摘同一个樱桃
                        res += grid[x2][y2];
                    }
                    f[k][x1][x2] = res;
                }
            }
        }
        return max(f.back().back().back(), 0);
    }
};

// n^4 妥妥的超时
class Solution {
private:
int N = -1;
public:
    void mydfs(int x, int y, int path, int c, vector<vector<int>>& grid) {
        bool flag = false, t = grid[x][y] == 1;
        if(t) {
            grid[x][y] = 0;
            path++;
        }
        if(x == grid.size()-1 && y == x) {
            if(c == 1) { // 重头再遍历一次
                mydfs(0, 0, path, 2, grid);
            } else {
                N = max(N, path);
            }
        } else {
            if(x < grid.size()-1 && grid[x+1][y] >= 0) {
                mydfs(x+1, y, path, c, grid);
            }
            if(y < grid.size()-1 && grid[x][y+1] >= 0) {
                mydfs(x, y+1, path, c, grid);
            }
        }
        if(t) grid[x][y] = 1; // 回溯 还原
    }
    int cherryPickup(vector<vector<int>>& grid) {
        mydfs(0, 0, 0, 1, grid);
        return max(N, 0);
    }
};