/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int ans;
    int line[9] = {0}, lr[17]={0}, rl[17]={0}; //1 <= n <= 9, 所以 2n-1 最大 17
    void myback(int row, int n) {
        if(row >= n) {
            ans++;
            return;
        }
        for (int i = 0; i < n; i++) {
            int index1 = row + i, index2 = row - i + n-1;
            if(line[i]==1 || lr[index1]==1 || rl[index2]==1)
                continue;
            line[i] = lr[index1] = rl[index2] = 1;
            myback(row+1, n);
            line[i] = lr[index1] = rl[index2] = 0; //回溯
        }
    }
    int totalNQueens(int n) {
        myback(0, n);
        return ans;
    }
};
// @lc code=end

