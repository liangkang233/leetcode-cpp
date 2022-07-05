/*
 * @lc app=leetcode.cn id=1374 lang=cpp
 *
 * [1374] 生成每种字符都是奇数个的字符串
 */

#include<iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    string generateTheString(int n) {
        string ans(n, 'a');
        if(n%2==0) ans.back()='b';
        return ans;
    }
};
// @lc code=end

