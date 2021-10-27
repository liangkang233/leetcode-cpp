/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        /* // 尝试用动态规划,发现规律就是4倍数必输
        vector<bool> map(n+1, 1);
        map[4] = false;
        for (int i = 5; i <= n; i++) {
            map[i] =!map[i-1] || !map[i-2] || !map[i-3];
            // 拿掉1或2或3个后，能让对方为false即可表明可以赢
        }
        return map[n]; */

        // 判断是否为4倍数
        return n & 3;
    }
};
// @lc code=end

