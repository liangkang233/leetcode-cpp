/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> myfun(string a){
        vector<int> b = {0, 0};
        sscanf(a.c_str(), "%d+%di", &b[0], &b[1]);
        return b;
    }
    string myfun1(int a, int b) {
        char temp[16];
        sprintf(temp, "%d+%ii", a, b);
        return string(temp);
    }
    string complexNumberMultiply(string num1, string num2) {
        auto a1 = myfun(num1);
        auto a2 = myfun(num2);
        // cout << a1[0] <<" " <<a1[1] << endl;
        // cout << a2[0] <<" " <<a2[1] << endl;
        return myfun1(a1[0]*a2[0]-a1[1]*a2[1], a1[1]*a2[0]+a1[0]*a2[1]);
    }
};
// @lc code=end

// "1+-1i"\n"1+1i"\n
// "1+-1i"\n"1+-1i"\n