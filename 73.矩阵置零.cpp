/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> v;
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m, false), column(n, false);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(!matrix[i][j]) {
                    v.push_back(i * n + j);
                }
            }
        }
        for (int i = 0; i < v.size(); i++) {
            int x = v[i] / n, y = v[i] % n;
            // cout << v[i] << " " << x << " " << y << endl;
            if(!row[x]) {
                for(int i = 0; i < n; i++) {
                    matrix[x][i] = 0;
                }
                row[x] = true;
            }
            if(!column[y]) {
                for (int i = 0; i < m; i++) {
                    matrix[i][y] = 0;
                }
                column[y] = true;
            }
        }
    }
};
// @lc code=end

