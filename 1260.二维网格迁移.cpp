/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 *
 * [1260] 二维网格迁移
 */

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> myswap(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                v[j][i] = grid[i][j];
            }
        }
        return v;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> v = myswap(grid);
        for (int i = 0, j = n-1; i < k; i++) {
            int t = v[j][m-1];
            copy(v[j].begin(), v[j].end()-1, v[j].begin()+1);
            v[j][0] = t;
            --j;
            if(j < 0) j = n-1;
        }
        vector<vector<int>> v1(v);
        for (int i = 0, index; i < n; i++) {
            index = (i + k) % n;
            v1[index] = v[i];
        }
        return myswap(v1);
    }
};
// @lc code=end
// [[1,2,3],[4,5,6],[7,8,9]]\n1
// [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]\n4
// [[1,2,3],[4,5,6],[7,8,9]]\n9

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int index1 = (i * n + j + k) % (m * n);
                ret[index1 / n][index1 % n] = grid[i][j];
            }
        }
        return ret;
    }
};
