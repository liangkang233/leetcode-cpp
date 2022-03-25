/*
 * @lc app=leetcode.cn id=2038 lang=cpp
 *
 * [2038] 如果相邻两个颜色均相同则删除当前颜色
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool winnerOfGame(string colors) {
        int Alice = 0, temp = 1;
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i-1] !=  colors[i]) {
                if(temp >= 3)
                    Alice += colors[i-1]=='A' ? temp-2 : 2-temp;
                temp = 1;
            }
            else
                temp++;
        }
        if(temp >= 3)
            Alice += colors.back()=='A' ? temp-2 : 2-temp;
        return Alice > 0;
    }
};
// @lc code=end
// "AAABBB"\n
// "AA"\n
// "ABBBBBBBAAAAA"\n
