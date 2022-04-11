/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

// @lc code=start
// 暴力 去重
class Solution {
public:
    int change(int n) {
        int t = 0;
        while(n > 0) {
            t += (n % 10) * (n % 10);
            n /= 10;
        }
        return t;
    }
    bool isHappy(int n) {
        unordered_set<int> myset;
        while (n > 0) {
            if(n == 1)
                return true;
            if(myset.find(n) != myset.end())
                break;
            myset.insert(n);
            n = change(n);
        }
        return false;
    }
};
// @lc code=end
// 2147483647
// 2
// 19
