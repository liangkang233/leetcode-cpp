/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        ans.reserve(m*n);
        int i = 0, j = 0; // i 为向下纵轴 j为向右横轴
        while (1) {
            while (i >= 0 && j < n) { // 斜向上
                ans.push_back(mat[i][j]);
                i--;
                j++;
            }
            i++; // 换下一列
            if(j == n) {
                i++;
                j--;
            }
            if(ans.size() == m*n) break;
            while (j >= 0 && i < m) { // 斜向下
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }
            j++; // 换下一列
            if(i == m) {
                i--;
                j++;
            }
            if(ans.size() == m*n) break;
        }
        return ans;
    }
};
// @lc code=end
// [[1,2,3],[4,5,6],[7,8,9],[10,11,12]]\n
// [[1,2,3,123,445,12],[4,5,6,2,3,4],[7,8,9,1,2,4],[12,10,11,12,4,5]]\n
