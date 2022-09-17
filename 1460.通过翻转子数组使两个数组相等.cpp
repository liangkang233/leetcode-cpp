/*
 * @lc app=leetcode.cn id=1460 lang=cpp
 *
 * [1460] 通过翻转子数组使两个数组相等
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size() != arr.size()) return false;
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for (int i = 0; i < target.size(); i++) {
            if(arr[i] != target[i])
                return false;
        }
        return true;
    }
};
// @lc code=end

