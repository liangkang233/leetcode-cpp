/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int L = 0, R = min(x, 46340) + 1;
        while (L < R) {
            int mid = (L + R) / 2;
            if(mid * mid <= x)
                L = mid+1;
            else
                R = mid;
        }
        return L-1;
    }
};
// @lc code=end
// 2147483647\n INT_MAX