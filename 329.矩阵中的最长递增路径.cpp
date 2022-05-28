/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<int>> maxp;
public:
    int mydfs(vector<vector<int>>& matrix, int i, int j) {
        int ans = 0;
        if(!maxp[i][j]) {
            if(i-1>=0 && matrix[i-1][j] > matrix[i][j])
                ans = max(ans, mydfs(matrix, i-1, j));
            if(j-1>=0 && matrix[i][j-1] > matrix[i][j])
                ans = max(ans, mydfs(matrix, i, j-1));
            if(i+1<matrix.size() && matrix[i+1][j] > matrix[i][j])
                ans = max(ans, mydfs(matrix, i+1, j));
            if(j+1<matrix[0].size() && matrix[i][j+1] > matrix[i][j])
                ans = max(ans, mydfs(matrix, i, j+1));
            maxp[i][j] = ans + 1;
        }
        return maxp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        maxp.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                ans = max(ans, mydfs(matrix, i, j));
            }
        }
        // for (auto &&i : maxp) {
        //     for(auto &ii : i)
        //         cout << ii << " ";
        //     cout << endl;
        // }
        return ans;
    }
};
// @lc code=end
// [[3,4,5],[3,2,6],[2,2,1]]\n