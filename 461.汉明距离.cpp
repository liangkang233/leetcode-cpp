/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        for (int i = 0; i < 31; i++) {
            if((x&1) ^ (y&1))
                ans += 1;
            x = x >> 1, y = y >> 1;
        }
        return ans;
    }
};
// @lc code=end

