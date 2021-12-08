/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row1 = matrix.size() - 1, line1 = matrix[0].size() - 1, row0 = 0, line0 = 0;
        vector<int> ans;
        while (1) {
            for (int i = line0; i <= line1; i++)
                ans.push_back(matrix[row0][i]);
            row0++;
            if (row0 > row1)
                break;
            for (int i = row0; i <= row1; i++)
                ans.push_back(matrix[i][line1]);
            line1--;
            if (line0 > line1)
                break;
            for (int i = line1; i >= line0; i--)
                ans.push_back(matrix[row1][i]);
            row1--;
            if (row0 > row1)
                break;
            for (int i = row1; i >= row0; i--)
                ans.push_back(matrix[i][line0]);
            line0++;
            if (line0 > line1)
                break;
        }
        return ans;
    }
};
// @lc code=end