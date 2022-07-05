// https://www.nowcoder.com/practice/0c9664d1554e466aa107d899418e814e?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int ans, m, n;
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>> 
     * @return int整型
     */
    void myfun(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        if(y+1 < n && grid[x][y+1] == '1')     myfun(grid, x, y+1);
        if(y-1 >= 0 && grid[x][y-1] == '1')    myfun(grid, x, y-1);
        if(x+1 < m && grid[x+1][y] == '1')     myfun(grid, x+1, y);
        if(x-1 >= 0 && grid[x-1][y] == '1')    myfun(grid, x-1, y);
    }
    int solve(vector<vector<char> >& grid) {
        m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    myfun(grid, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};