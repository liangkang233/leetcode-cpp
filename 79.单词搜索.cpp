/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool mydfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int j, int index) {
        if (index >= word.size())
            return true;
        // cout << i << " j: " << j << "  " << word[index] << endl;
        if(i-1 >= 0 && !visited[i-1][j] && word[index] == board[i-1][j]) {
            visited[i-1][j] = true;
            if (mydfs(board, word, visited, i-1, j, index+1))
                return true;
            visited[i-1][j] = false;
        }
        if(j-1 >= 0 && !visited[i][j-1] && word[index] == board[i][j-1]) {
            visited[i][j-1] = true;
            if (mydfs(board, word, visited, i, j-1, index+1))
                return true;
            visited[i][j-1] = false;
        }        
        if(i+1 < board.size() && !visited[i+1][j] && word[index] == board[i+1][j]) {
            visited[i+1][j] = true;
            if (mydfs(board, word, visited, i+1, j, index+1))
                return true;
            visited[i+1][j] = false;
        }        
        if(j+1 < board[0].size() && !visited[i][j+1] && word[index] == board[i][j+1]) {
            visited[i][j+1] = true;
            if (mydfs(board, word, visited, i, j+1, index+1))
                return true;
            visited[i][j+1] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(),false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (mydfs(board, word, visited, i, j, 1))
                        return true;
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
};
// @lc code=end

// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"SEE"
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCB"
// [["a","a"]]\n"aaa"