/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int row0=0, row1=n-1, line0=0, line1=n-1, count = 1;
        while (1) {
            for (int i = line0; i <= line1; i++)
                ans[row0][i]=count++;
            row0++;
            if (count > n*n)
                break;
            
            for (int i = row0; i <= row1; i++)
                ans[i][line1]=count++;
            line1--;
            if (count > n*n)
                break;

            for (int i = line1; i >= line0; i--)
                ans[row1][i]=count++;
            row1--;
            if (count > n*n)
                break;

            for (int i = row1; i >= row0; i--)
                ans[i][line0]=count++;
            line0++;
            if (count > n*n)
                break;
        }
        return ans;
    }
};
// @lc code=end

