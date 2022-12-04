/* 面试题 01.08. 零矩阵
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

示例 1：
    输入：
        [
        [1,1,1],
        [1,0,1],
        [1,1,1]
        ]
    输出：
        [
        [1,0,1],
        [0,0,0],
        [1,0,1]
        ]

示例 2：
    输入：
        [
        [0,1,2,0],
        [3,4,5,2],
        [1,3,1,5]
        ]
    输出：
        [
        [0,0,0,0],
        [0,4,5,0],
        [0,3,1,0]
        ] 
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row(m, 0), column(n, 0);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    column[j] = 1;
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if(row[i] == 1 || column[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};