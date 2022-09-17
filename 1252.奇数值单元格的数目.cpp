/*
 * @lc app=leetcode.cn id=1252 lang=cpp
 *
 * [1252] 奇数值单元格的数目
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int ans = 0, a = 0;
        vector<int> r(m), c(n);
        for (int i = 0; i < indices.size(); i++) {
            r[indices[i][0]]++;
            c[indices[i][1]]++;
        }
        for (int i = 0; i < m; i++) {
            if(r[i] % 2) a++;
        }
        for (int i = 0; i < n; i++) {
            if(c[i] % 2) {
                ans += m-a;
            } else {
                ans += a;
            }
        }
        return ans;
    }
};
// @lc code=end
// 2\n3\n[[0,1],[1,1]]\n2\n2\n[[1,1],[0,0]]