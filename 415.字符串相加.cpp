/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        char flag = 0;
        for (int i=num1.size()-1, j=num2.size()-1; i>=0 || j>=0 || flag>0; i--, j--) {
            char temp1 = 0, temp2 = 0;
            if(i >= 0)    temp1 = num1[i] - '0';
            if(j >= 0)    temp2 = num2[j] - '0';
            int temp = flag + temp1 + temp2;
            if(temp >= 10) {
                flag = 1;
                temp -= 10;
            }
            else
                flag = 0;
            // cout << i << " " << j  << " " << temp << endl;
            ans.push_back(temp + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

// ""1234"\n"5646""