/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
// 74题进阶，由题意 任意坐标右下方 全部大于等于该坐标值 左上方全部小于等于该值 时间复杂度O(logm + logn)
// 所以先对第一行列二分删除多余大于target的列 再行二分删除小于target的行 不断迭代下去
class Solution {
public:
    int myupper_bound(vector<vector<int>>& matrix, int row, int column, int target) {
        int L = 0, R = column + 1;
        while (L < R) {
            int mid = (L + R) >> 1;
            if(matrix[row][mid] <= target)
                L = mid+1;
            else
                R = mid;
        }
        return L;
    }
    int mylower_bound(vector<vector<int>>& matrix, int row, int column, int target) {
        int L = row, R = matrix.size();
        while (L < R) {
            int mid = (L + R) >> 1;
            if(matrix[mid][column] < target)
                L = mid+1;
            else
                R = mid;
        }
        return L;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 有效范围 行为 row->matrix.end()-1 列为 0-cloumn
        int row = 0, column = matrix[0].size()-1; 
        while (1) {
            // std库做法
            // auto it = upper_bound(matrix[row].begin(), matrix[row].begin()+column+1, target);
            // if(it == matrix[row].begin())
            //     break;
            // column = distance(matrix[row].begin(), it) - 1; // column 右边删去
            column = myupper_bound(matrix, row, column, target) - 1; // column 右边删去
            if(column < 0) //target 比范围内最小值还小
                break;
            row = mylower_bound(matrix, row, column, target);
            if(row == matrix.size()) //target 比范围内最大值还大
                break;
            if(matrix[row][column] == target)
                return true;
        }
        return false;
    }
};
// @lc code=end


// 官方的Z字寻找 时间复杂度 O(n+m)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0) {
            if (matrix[x][y] == target)
                return true;
            if (matrix[x][y] > target)
                --y;
            else
                ++x;
        }
        return false;
    }
};
