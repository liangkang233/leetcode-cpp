/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int mydfs(vector<vector<int>>& grid, int i, int j) {
        int count = 0;
        if(i >=0 && i < grid.size() && j >=0 && j < grid[0].size() && grid[i][j] == 1) {
            count++;
            grid[i][j] = -1;
            count += mydfs(grid, i, j+1);
            count += mydfs(grid, i, j-1);
            count += mydfs(grid, i+1, j);
            count += mydfs(grid, i-1, j);
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans = max(mydfs(grid, i, j), ans);
            }
        }
        // 略过将1还原回去的步骤
        return ans;
    }
};
// @lc code=end

/* python3
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        ans , res = 0, 0
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    ans = 1
                    grid[i][j] = 0
                    queue = []
                    queue.append([i,j])
                    while queue:
                        v = queue.pop(0)
                        temp_l = [[v[0], v[1] + 1],
                                  [v[0], v[1] - 1],
                                  [v[0] + 1, v[1]],
                                  [v[0] - 1, v[1]]]
                        for [x,y] in temp_l:
                            # print(x, y, " now")
                            if 0 <= x < n and 0 <= y < m and grid[x][y] == 1:
                                queue.append([x,y])
                                ans += 1
                                grid[x][y] = 0
                res = max(res,ans)
        return res
*/