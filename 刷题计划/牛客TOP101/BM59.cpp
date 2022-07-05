// https://www.nowcoder.com/practice/c76408782512486d91eea181107293b6?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int ans = 0;
public:
    /**
     * 
     * @param n int整型 the n
     * @return int整型
     */
    bool isok(vector<vector<int>>& v, int x, int y) { // 只需要考虑之前的
        for (int i = 0; i < x; i++) {
            if(v[i][y] == 1) return false;
        }
        for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
            if(v[i][j] == 1) return false;
        }
        for (int i = x, j = y; i >= 0 && j < v[0].size(); i--, j++) {
            if(v[i][j] == 1) return false;
        }
        return true;
    }
    void mydfs(vector<vector<int>>& v, int x) {
        if(x == v.size()) {
            ans++;
            return ;
        } 
        for (int y = 0; y < v[0].size(); y++) {
            if(isok(v, x, y)) {
                v[x][y] = 1;
                mydfs(v, x+1);
                v[x][y] = 0;
            }
        }
    }
    int Nqueen(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        mydfs(v, 0); // 由题意 每行 都有一个皇后
        return ans;
    }
};