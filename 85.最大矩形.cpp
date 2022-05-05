/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// 二维双向单调栈
// @lc code=start
class Solution {
public:
    // 单调栈 以每一列为
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())  return 0;
        int row = matrix.size(), column = matrix[0].size(), ans = 0;
        vector<vector<int>> left(row, vector<int>(column));
        for (int i = 0; i < row; i++) { // left 为 ij下 左侧最多连续的1
            for (int j = 0; j < column; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;
                }
            }
        }
        for (int j = 0; j < column; j++) {
            vector<int> up(row, -1), down(row, row);
            stack<int> st;
            for (int k = 0; k < row; k++) {
                while (!st.empty() && left[k][j] < left[st.top()][j]) { // 对应j列 第一个小于 left 单调栈 down坐标 有效坐标区间需要减一
                    down[st.top()] = k;
                    st.pop();
                }
                st.push(k);
            }
            st = stack<int>();
            for (int k = row-1; k >= 0; k--) { // 对应j列 的left单调栈 单调栈 up坐标 有效坐标区间需要减一
                while (!st.empty() && left[k][j] < left[st.top()][j]) {
                    up[st.top()] = k;
                    st.pop();
                }
                st.push(k);
            }
            for (int i = 0; i < row; i++)
                ans = max(ans, (down[i] - up[i] - 1) * left[i][j]);
        }
        return ans;
    }
};
// @lc code=end
// [["0"]]


class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        int m = matrix.size();
        if (m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;
                }
            }
        }

        int ret = 0;
        for (int j = 0; j < n; j++) { // 对于每一列，使用基于柱状图的方法
            vector<int> up(m, 0), down(m, 0);

            stack<int> stk;
            for (int i = 0; i < m; i++) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }
            stk = stack<int>();
            for (int i = m - 1; i >= 0; i--) {
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }

            for (int i = 0; i < m; i++) {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }
};