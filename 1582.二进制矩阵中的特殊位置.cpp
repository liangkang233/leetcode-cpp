/*
 * @lc app=leetcode.cn id=1582 lang=cpp
 *
 * [1582] 二进制矩阵中的特殊位置
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        unordered_set<int> ms;
        for(int i = 0; i < mat.size(); i++) {
            // unordered_set<int> ms1;
            vector<int> v;
            if(ms.size() == mat[0].size()) break;
            for (int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 1)
                    v.push_back(j);
            }
            if(v.size() == 1 && ms.find(v[0]) == ms.end()) {
                int j = v[0];
                // cout << i << " T " << j << endl;
                for (int k = i+1; k <= mat.size(); k++) {
                    if(k == mat.size()) {
                        ans++;
                        // cout << i << " " << j << endl;
                    } else if(mat[k][j] == 1) {
                        break;
                    }
                }
            }
            for (auto& it : v) {
                ms.insert(it);
            }
        }
        return ans;
    }
};
// @lc code=end
// [[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,1],[0,0,0,0,1,0,0,0],[1,0,0,0,1,0,0,0],[0,0,1,1,0,0,0,0]]
// [[0,0,0,0,1,0,0,1,0,0],[0,0,1,0,0,0,0,0,0,0],[0,1,0,0,0,0,0,1,0,1],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,1,0]]


// 直接记录行 列 和 即可 简洁美丽
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rowsSum(m);
        vector<int> colsSum(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowsSum[i] += mat[i][j];
                colsSum[j] += mat[i][j];
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && rowsSum[i] == 1 && colsSum[j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};
