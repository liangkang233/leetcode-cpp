/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
// 参考题解做法， 以n-m下标为边界  左边界限内黑名单数字 必定 有一一映射到右边黑名单的数字
class Solution {
private:
    int count;
    unordered_map<int, int> mp; // 左区间中黑名单值映射至右区间白名单值
public:
    Solution(int n, vector<int>& blacklist) {
        count = n - blacklist.size();
        sort(blacklist.begin(), blacklist.end());
        // unordered_set<int> ms(blacklist.begin(), blacklist.end());
        int i = 0, j = 0, val = count;
        while (j < blacklist.size() && blacklist[j] < count) j++;
        while (i < blacklist.size() && blacklist[i] < count) {
            while (j < blacklist.size() && blacklist[j] == val) {
                j++;
                val++;
            }
            mp[blacklist[i++]] = val++;
        }
    }
    int pick() {
        int k = rand() % count;
        if(mp.find(k) != mp.end())
            return mp[k];
        return k;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end
// ["Solution","pick","pick","pick"]\n[[1,[]],[],[],[]]


class Solution {
private:
    vector<int> re;
public:
    Solution(int n, vector<int>& blacklist) {
        re.reserve(n - blacklist.size());
        sort(blacklist.begin(), blacklist.end());
        for (int i = 0, j = 0; i < n; i++) {
            if(j < blacklist.size() && i == blacklist[j]) {
                j++;
                continue;
            }
            re.push_back(i);
        }
    }
    int pick() {
        return re[rand() % re.size()];
    }
};