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


// 二刷 采用48题目的循环思路  空间效果不如上面的代码...
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int index = 1;
        for (int i = 0, L = n-1; L >= 0; L-=2, i++) { //假设边长为L 四条边都只能修改L-1次 初始下标ans[i][i]
            if(L==0) {
                ans[i][i] = index;
                break;
            }
            for (int j = 0; j < L; j++, index++) {
                ans[i][i+j] = index;
                ans[i+j][n-1-i] = index + L;
                ans[n-1-i][n-1-i-j] = index + 2*L;
                ans[n-1-i-j][i] = index + 3*L;
            }
            index += 3*L;
        }
        return ans;
    }
};
