// https://www.nowcoder.com/practice/7a71a88cdf294ce6bdf54c899be967a2?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int mydfs(vector<vector<int>>& matrix, vector<vector<int>>& path, int x, int y) {
        int p = 1, a = matrix[x][y];
        if(x-1 >= 0 && matrix[x-1][y] > a) {
            if(path[x-1][y] == 0)
                path[x-1][y] = mydfs(matrix, path, x-1, y);
            p = max(p, 1+path[x-1][y]);
        }
        if(x+1 < path.size() && matrix[x+1][y] > a) {
            if(path[x+1][y] == 0)
                path[x+1][y] = mydfs(matrix, path, x+1, y);
            p = max(p, 1+path[x+1][y]);
        }
        if(y-1 >= 0 && matrix[x][y-1] > a) {
            if(path[x][y-1] == 0)
                path[x][y-1] = mydfs(matrix, path, x, y-1);
            p = max(p, 1+path[x][y-1]);
        }
        if(y+1 < path[0].size() && matrix[x][y+1] > a) {
            if(path[x][y+1] == 0)
                path[x][y+1] = mydfs(matrix, path, x, y+1);
            p = max(p, 1+path[x][y+1]);
        }
        return p;
    }
    int solve(vector<vector<int> >& matrix) {
        int ans = 1;
        vector<vector<int>> path(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if(path[i][j] > 0)
                    continue;
                ans = max(mydfs(matrix, path, i, j), ans);
            }
        }
        return ans;
    }
};