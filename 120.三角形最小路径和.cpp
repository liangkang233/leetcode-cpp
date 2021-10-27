/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size(), ans = triangle[0][0];
        vector<int> myarray(size, 0);   //为了省空间 只用一维容器
        myarray[0] = ans;
        for (int i = 1; i < size; i++) {
            myarray[i] = triangle[i][i] + myarray[i-1];
            ans = myarray[i];
            for (int j = i-1; j >= 0; j--) { //为了防止j调用到修改过的j-1，j用逆序的方式遍历
                if (j==0)
                    myarray[j] = triangle[i][j] + myarray[j];
                else //myarry 代表上一行的最小值容器，所以此处 j-1 是还未修改的左边 j是上边
                    myarray[j] = triangle[i][j] + min(myarray[j], myarray[j-1]);
                ans = min(myarray[j], ans);
            }
        }
        return ans;
    }
};
// @lc code=end

