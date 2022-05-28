/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(), column = mat[0].size();
        queue<int> myque;
        vector<vector<int>> ans(row, vector<int>(column, -1));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if(mat[i][j] == 0)
                    myque.push(100000*i + j);
            }
        }
        int depth = -1;
        while (!myque.empty()) {
            int size = myque.size();
            depth++;
            for (int i = 0; i < size; i++) {
                int x = myque.front() / 100000, y = myque.front() % 100000;
                myque.pop();
                if(ans[x][y] >= 0) // 已经扫描过
                    continue;
                // cout << x << " " << y << endl;
                ans[x][y] = depth;
                if(y+1 < column && ans[x][y+1] < 0) {
                    myque.push(100000*x + y+1);
                }
                if(y-1 >=0 && ans[x][y-1] < 0) {
                    myque.push(100000*x + y-1);
                }
                if(x+1 < row && ans[x+1][y] < 0) {
                    myque.push(100000*(x+1) + y);
                }
                if(x-1 >= 0 && ans[x-1][y] < 0) {
                    myque.push(100000*(x-1) + y);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
// [[0,0,0],[0,1,0],[1,1,1]]\n
// [[1,1,1,0,1,1,0,1],[1,1,1,1,1,1,0,1],[1,1,1,1,1,1,1,1],[0,1,1,1,0,1,0,1],[1,1,1,1,0,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,1,0,1,1],[1,1,1,1,1,1,1,1]]\n