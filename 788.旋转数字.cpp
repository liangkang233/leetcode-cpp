/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
    int ans = 0;
public:
    void mydfs(string s, int n, bool flag) {
        if(!s.empty() && stoi(s) > n) return;
        if(flag) ans++;
        // cout << s << endl;
        if(!s.empty()) // 确保不会生成前导0 导致 00001 和 001 这样的重复递归
            mydfs(s + '0', n, flag);
        mydfs(s+'1', n, flag);
        mydfs(s+'8', n, flag);
        mydfs(s+'2', n, true); // 有2 5 6 9元素一定是好数
        mydfs(s+'5', n, true);
        mydfs(s+'6', n, true);
        mydfs(s+'9', n, true);
    }
    int rotatedDigits(int n) {
        // 即数位必须包含 2 5 6 9    1、0、8个数不限制即可
        mydfs("", n, false);
        return ans;
    }
};
// @lc code=end

