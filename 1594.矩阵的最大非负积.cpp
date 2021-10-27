/*
 * @lc app=leetcode.cn id=1594 lang=cpp
 *
 * [1594] 矩阵的最大非负积
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// @lc code=start
class Solution {
public:
    // 官方的空间使用的比较大，维护的数组可以节省为一维
/*     int maxProductPath(vector<vector<int>>& grid) {
        const int mod = 1000000000 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> maxgt(m, vector<long long>(n));
        vector<vector<long long>> minlt(m, vector<long long>(n));

        maxgt[0][0] = minlt[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            maxgt[0][i] = minlt[0][i] = maxgt[0][i - 1] * grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            maxgt[i][0] = minlt[i][0] = maxgt[i - 1][0] * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (grid[i][j] >= 0) {
                    maxgt[i][j] = max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                    minlt[i][j] = min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                } else {
                    maxgt[i][j] = min(minlt[i][j - 1], minlt[i - 1][j]) * grid[i][j];
                    minlt[i][j] = max(maxgt[i][j - 1], maxgt[i - 1][j]) * grid[i][j];
                }
            }
        }
        if (maxgt[m - 1][n - 1] < 0) {
            return -1;
        } else {
            return maxgt[m - 1][n - 1] % mod;
        }
    } */
    // 原来是题目理解错了，取余操作只在最后进行，中间的值可不能取余，所以必须用longlong容器 
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        vector<long long> dp_max(n), dp_min(n);           
        dp_max[0] = grid[0][0], dp_min[0]=dp_max[0];
        auto fun =[](long long num)->int{ return num % 1000000007; };
        for (int j = 1; j < n; j++) {
            dp_max[j] = max( dp_max[j-1]*grid[0][j], dp_min[j-1]*grid[0][j]) ;
            dp_min[j] = min( dp_max[j-1]*grid[0][j], dp_min[j-1]*grid[0][j]) ;
        }        
        // 维护两个动态规划数组，分别为上一行的 最大 和 最小值
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long t_max1=LLONG_MIN, t_max2, t_min1=LLONG_MAX, t_min2;
                // 注意:两个int相乘赋给longlong 不会运算时转换，必须运算前手动强转
                if (j > 0)  {
                    t_max1 = max( dp_max[j-1]*grid[i][j], dp_min[j-1]*grid[i][j]) ;
                    t_min1 = min( dp_max[j-1]*grid[i][j], dp_min[j-1]*grid[i][j]) ;
                }
                t_max2 = max( dp_max[j]*grid[i][j], dp_min[j]*grid[i][j]) ;
                t_min2 = min( dp_max[j]*grid[i][j], dp_min[j]*grid[i][j]) ;
                dp_max[j] = max(t_max1, t_max2) ;
                dp_min[j] = min(t_min1, t_min2) ;
            }
        }
        return dp_max[n-1]>=0 ? fun(dp_max[n-1]) : -1;
    } 
};
// @lc code=end

/* 测试案例：
[[1,-1,0,-3,4,3,-3,3,-1,3,0,0,-4,2],[2,-2,-3,-4,0,-2,-3,3,1,4,1,-3,-1,-4],[-4,4,-4,-4,2,-4,3,0,-2,-4,3,4,-1,0],[-3,3,-4,-4,3,4,4,1,-1,-1,0,3,4,1],[1,3,-4,2,2,-3,1,-3,-4,-4,-1,-4,-4,4],[1,1,-1,1,-1,-1,3,-4,-1,2,-2,3,-4,0],[1,0,3,3,1,4,1,1,-4,-1,-3,4,-4,4],[4,3,2,3,3,-1,2,-4,1,3,3,1,3,4],[4,4, 4, 4,2,-2,2,-1,3,-2,2,4,-2,-1],[-2,3,4,4,3,3,-2,-1,3,-3,4,-2,-1,-4],[4,3,3,3,-3,1,2,-4,-1,4,-3,-3,2,0],[3,3,0,1,-4,-4,-3,3,-2,-4,2,4,-3,3],[-3,0,1,3,0,0,0,-4,-1,4,-1,-3,1,1],[-1,4,-3,1,-3,-1,2,1,-3,-1,-4,3,4,1]]\n
*/

