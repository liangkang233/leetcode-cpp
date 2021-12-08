/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start

// 使用 bitmap 设定哈希表，例如存入值 3 即为 1 >> (3-1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 建立哈希表集合 line为行 row为列 group为团（团按照从左到右 从上到下的顺序）
        int row[9] = {0}, line[9] = {0}, group[9] = {0};
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                // cout << "i=" << i << " j=" << j << " group=" << i/3*3 + j/3 << endl;
                if(board[i][j] == '.')
                    continue;
                int num = 1 << board[i][j]-'1', index = i/3*3 + j/3;
                // cout << board[i][j]-'1' << " " << num << endl;
                if ( (row[i] & num) != 0) // 行 有重复
                // 类似这样的 不加括号优先级有问题 if (row[i] & num != 0){
                    return false;
                row[i] += num;
                if ( (line[j] & num) != 0) // 列 有重复
                    return false;
                line[j] += num;
                if ( (group[index] & num) != 0) // 组合 有重复
                    return false;
                group[index] += num;
            }
        }
        return true;
    }
};
// @lc code=end

