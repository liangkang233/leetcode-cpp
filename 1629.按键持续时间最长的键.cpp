/*
 * @lc app=leetcode.cn id=1629 lang=cpp
 *
 * [1629] 按键持续时间最长的键
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = keysPressed[0];
        int max_time = releaseTimes[0];
        for (int i = 1; i < keysPressed.size(); i++) {
            if(releaseTimes[i] - releaseTimes[i-1] > max_time) {
                max_time = releaseTimes[i] - releaseTimes[i-1];
                ans = keysPressed[i];
            }
            else if(releaseTimes[i] - releaseTimes[i-1] == max_time)
                ans = max(ans, keysPressed[i]);
        }
        return ans;
    }
};
// @lc code=end

// [12,23,36,46,62]\n"spuda"
// [12,23,36,46,59]\n"spuda"