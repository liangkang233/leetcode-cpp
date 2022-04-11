/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 杨辉三角的某一行i 可以看作 排列组合的 Ci 
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 1);
        int M = rowIndex;
        long long temp = 1;
        for(int i = 1; i < rowIndex; i++) {
            temp = temp*M/i; // temp *= M/i M/i出现浮点数会强转为整数 temp不用longlong int会溢出
            M--;
            ans[i] = temp;       
        }
        return ans;
    }
};
// @lc code=end

