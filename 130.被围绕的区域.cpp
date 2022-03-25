/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
// typedef pair<int, int> mypair;
class Solution {
public:
    bool mydfs(vector<vector<char>>& board, int xy, unordered_set<int>& temp_set) {
        int x = xy/board[0].size(), y = xy - x*board[0].size();
        bool flag = false;
        if(x-1<0 || y-1<0 || x+1>=board.size() || y+1>=board[0].size())
            flag = true;
        xy = (x-1)*board[0].size() + y;
        if(x-1>=0 && board[x-1][y] == 'O' && temp_set.find(xy) == temp_set.end()) {
            temp_set.insert(xy);
            flag = mydfs(board, xy, temp_set) || flag;
        }
        xy = x*board[0].size() + y-1;
        if(y-1>=0 && board[x][y-1] == 'O' && temp_set.find(xy) == temp_set.end()) {
            temp_set.insert(xy);
            flag = mydfs(board, xy, temp_set) || flag;
        }
        xy = (x+1)*board[0].size() + y;
        if(x+1<board.size() && board[x+1][y] == 'O' && temp_set.find(xy) == temp_set.end()) {
            temp_set.insert(xy);
            flag = mydfs(board, xy, temp_set) || flag;
        }
        xy = x*board[0].size() + y+1;
        if(y+1<board[0].size() && board[x][y+1] == 'O' && temp_set.find(xy) == temp_set.end()) {
            temp_set.insert(xy);
            flag = mydfs(board, xy, temp_set) || flag;
        }
        return flag;
    }
    void solve(vector<vector<char>>& board) {
        unordered_set<int> myset;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int xy = i*board[0].size() + j;
                if (board[i][j] == 'O' && myset.find(xy) == myset.end()) {
                    unordered_set<int> temp_set;
                    temp_set.insert(xy);
                    if(!mydfs(board, xy, temp_set)) { //被围住了
                        for (auto it = temp_set.begin(); it != temp_set.end(); it++) {
                            int x = *it/board[0].size(), y = *it - x*board[0].size();
                            board[x][y] = 'X';
                        }
                    }
                    myset.insert(temp_set.begin(), temp_set.end());
                }
            }
        }
    }
};
// @lc code=end
// [["X"]]\n
// [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","O","X"]]
// [["X","O","X","X"],["X","O","X","X"],["X","X","O","X"],["X","O","X","X"]]

class Solution {
public:
    int n, m;

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        if (n == 0) {
            return;
        }
        m = board[0].size();
        for (int i = 0; i < n; i++) {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m - 1; i++) {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
