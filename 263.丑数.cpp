/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        //任何数可以分解为质数相乘，且表达形式唯一
        if(n<1) return false;
        while (n%2==0) n/=2;
        while (n%3==0) n/=3;
        while (n%5==0) n/=5;
        return n==1 ? true : false;
    }
};
// @lc code=end

