/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int row[9] = {0}, line[9] = {0}, group[9] = {0}; // 自定义bitmap

    bool myback(vector<vector<char>>& board, int id) {
        if (id >= 81)
            return true;
        int i = id / 9, j = id - i*9, index = i/3*3 + j/3;
        // cout << id << " " << i << " " << j << " " << index << endl;
        if ( board[i][j] != '.' ) // 跳过该值
            return myback(board, id+1);
        for (int num = 0; num < 9; num++) {
            int  check = 1 << num;
            if( (row[i]&check)!= 0 || (line[j]&check)!= 0 || (group[index]&check)!= 0 ) //该数字有重复，跳过
                continue;
            board[i][j] = '1' + num; //假定该数字是答案
            row[i] += check;
            line[j] += check;
            group[index] += check;
            if(myback(board, id+1)) //测试该数字递归下去的结果
                return true;
            else {  //无效数字，回溯
                board[i][j] = '.';
                row[i] -= check;
                line[j] -= check;
                group[index] -= check;
            }
        }
        return false;       
    }

    // 类似n皇后的回溯做法
    void solveSudoku(vector<vector<char>>& board) {
        // 必须先把已经存在的值填入作为判断依据,题意说明该数独一定有解
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if ( board[i][j] != '.' ) {
                    int index = i/3*3 + j/3, check = 1 << (board[i][j] - '1');
                    row[i] += check;
                    line[j] += check;
                    group[index] += check;
                }
            }
        }        
        myback(board, 0);//题目规定必定有唯一答案，不必判断这里的返回值了
    }
};
// @lc code=end

int main () {
    Solution sol;
    vector<vector<char>>test = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    sol.solveSudoku(test);
    return 0;
}