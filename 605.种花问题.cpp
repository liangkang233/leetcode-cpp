/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */

#include <iostream>
#include <vector>
using namespace std;

// 规律
// 首尾可为1 -> (i+1)/2; 
// 仅一个可为1 -> i/2; 
// 首尾皆不可为1 -> (i-1)/2

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 找规律，若是 中间的0个数为i 则可以种 (i-1)/2 
        // 其次 要考虑首尾 首/为0 即i+i, 
        int ans = 0, temp = 1;//首的temp+1
        for (auto &&i : flowerbed) {
            if(i == 0)
                temp++;
            else {
                ans += (temp-1)/2;
                temp = 0;
            }
        }
        ans += temp/2; // 尾的temp+1,再执行 (temp-1)/2  等价左式
        return ans >= n;
    }
};
// @lc code=end

