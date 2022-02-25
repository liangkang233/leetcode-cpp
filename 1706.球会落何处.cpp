/*
 * @lc app=leetcode.cn id=1706 lang=cpp
 *
 * [1706] 球会落何处
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for (int j = 0; j < grid[0].size(); j++) {
            int k = j, i = 0; //k为球的当前列位置，i为行
            for (; i < grid.size(); i++) {
                int temp = grid[i][k]>0 ? k+1 : k-1;
                if(temp < 0 )
                    temp = 1;
                else if(temp >= grid[0].size())
                    temp = -1;
                else 
                    temp = grid[i][temp];
                if(grid[i][k] == temp)
                    k += temp;
                else
                    break;
            }
            if(i!=grid.size())
                k = -1;
            ans.push_back(k);
        }
        return ans;
    }
};
// @lc code=end

// [[1]]\n
