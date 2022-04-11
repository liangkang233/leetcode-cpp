/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 替换规律 列变行 i行变为(n-i-1) n为size 
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // vector<int> temp1(n, 0), temp2(n, 0), temp3(n, 0), temp4(n, 0);
        // 每次转移外面一圈 该圈的大小为i 圈的起始下标index
        for (int i = n, index = 0; i > 0 ;i-=2, index++) { 
            // cout << "test " << i << endl;
            vector<int> temp1(i, 0), temp2(i, 0), temp3(i, 0), temp4(i, 0);
            for (int j = 0; j < i; j++) {   // 复制副本
                temp1[j] = matrix[index][index+j];
                temp2[j] = matrix[index+j][n-1-index];
                temp3[j] = matrix[n-1-index][n-1-index-j];
                temp4[j] = matrix[n-1-index-j][index];
                // cout << j << " " << temp1[j] << " "<< temp2[j] << " "<< temp3[j] << " "<< temp4[j] << endl;
            }
            for (int j = 0; j < i; j++) {   // 替换填充
                matrix[index][index+j] = temp4[j];
                matrix[index+j][n-1-index] = temp1[j];
                matrix[n-1-index][n-1-index-j] = temp2[j];
                matrix[n-1-index-j][index] = temp3[j];
            }
        }
    }
};
// @lc code=end
// [[1,2],[3,4]]\n
// [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]\n
// [[1,2,3,4,5,6,7,8],[9,10,11,12,13,14,15,16],[17,18,19,20,21,22,23,24],[25,26,27,28,29,30,31,32],[33,34,35,36,37,38,39,40],[41,42,43,44,45,46,47,48],[49,50,51,52,53,54,55,56],[57,58,59,60,61,62,63,64]]\n

// 秒杀我的反转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};


// 旋转拆解
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
        // 主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};