/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
// O(n) 遍历生成
class Solution {
public:
    void mydfs(vector<int>& ans, const int& n, int now, int count, int N) { // now为当前遍历值 N代表位数
        if(N == 0) {
            if(now <= n)
                ans[now] = count;
            return;
        }
        mydfs(ans, n, now * 2 + 1, count+1, N-1);
        mydfs(ans, n, now * 2, count, N-1);
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        int N = 0, temp = n;
        for (; temp > 0; N++) 
            temp /= 2;
        mydfs(ans, n, 0, 0, N);
        return ans;
    }
};
// @lc code=end

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        int highBit = 0;
        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                highBit = i; // 牛的 遍历过程中 只有 最高位为1会触发修改 如此求最高位
            }
            bits[i] = bits[i - highBit] + 1;
        }
        return bits;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        int highBit = 1;
        for (int i = 1; i <= n; i++) {
            if (i == 2 * highBit)
                highBit *= 2;
            bits[i] = bits[i - highBit] + 1;
        }
        return bits;
    }
};