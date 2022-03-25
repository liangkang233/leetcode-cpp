/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// @lc code=start
// bfs只要找到路就可以return 最先找到的必定等于最短值, 标记走过的路直接赋值原数组1 不用set
class Solution {
public:
    int dir[8][8]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,-1},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1) return 1;
        if(grid[0][0]!=0) return -1;
        if(grid[n-1][m-1]==1) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;
        int ans=1;
        while(!q.empty()){
            int k=q.size();
            for(int r=0;r<k;r++){
                pair<int,int> p=q.front();
                q.pop();
                int x=p.first;
                int y=p.second;
                for(int i=0;i<8;i++){
                    int xx=x+dir[i][0];
                    int yy=y+dir[i][1];
                    if(xx>=0&&yy>=0&&xx<n&&yy<m){
                        if(grid[xx][yy]==0){
                            q.push({xx,yy});
                            grid[xx][yy]=1;
                        }
                        if(xx==n-1&&yy==m-1){
                            return ans+1;
                        }
                    }
                }
            }
            ans+=1;
        } 
        return -1;
    }
};
// @lc code=end
// [[0,0,0],[1,1,0],[1,1,0]]\n
// [[0,0,0],[0,1,0],[0,0,0]]\n
// [[1,0,0],[1,1,0],[1,1,0]]\n
// [[0,1,1,0,0,0],[0,1,0,1,1,0],[0,1,1,0,1,0],[0,0,0,1,1,0], [1,1,1,1,1,0],[1,1,1,1,1,0]]
// [[0,0,1,1,0,0],[0,0,0,0,1,1],[1,0,1,1,0,0],[0,0,1,1,0,0],[0,0,0,0,0,0],[0,0,1,0,0,0]]


// dfs会超时，找寻一个解或答案时bfs有效，否则比较全部路径时用dfs更好
class Solution {
public:
    int ans = INT_MAX, n;
    void mydfs(int xy, int now, vector<vector<int>>& grid) {
        int x = xy/n, y = xy - x*n;
        if(xy == n*n - 1) {
            ans = min(now, ans);
            return ;
        }
        // vector<int> poll{xy-1, xy-1-n, xy-n, xy-n+1, xy+1, xy+n+1, xy+n, xy+n-1}; // 这样会多算 例如x=0 y=1 还能x-1
        vector<int> xx{0,0,1,1,1,-1,-1,-1};
        vector<int> yy{1,-1,0,1,-1,0,1,-1};
        for (int i = 0; i < 8; i++) {
            int x1 = x + xx[i], y1 = y + yy[i], xy1 = x1*n + y1;
            if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && grid[x1][y1] == 0) {
                grid[x1][y1] = 1;
                mydfs(xy1, now+1, grid);
                grid[x1][y1] = 0;
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        unordered_set<int> myset;
        n = grid.size();
        if(grid[0][0] == 0 && grid[n-1][n-1] == 0) {
            grid[0][0] = 1;
            mydfs(0, 0, grid);
        }
        return ans==INT_MAX ? -1 : ans+1;
    }
};