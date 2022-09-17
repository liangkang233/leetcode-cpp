/*
 * @lc app=leetcode.cn id=672 lang=cpp
 *
 * [672] 灯泡开关 Ⅱ
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    unordered_set<string> ms;
    void fun1(string& s, int i, int x) {
        for(; i < s.size(); i+=x) {
            s[i] = s[i] == '1' ? '0' : '1';
        }
    }
    void mydfs(string& s, int pre) {
        if(pre == 0) {
            ms.insert(s);
            return ;
        }
        pre--;
        fun1(s, 0, 1);
        mydfs(s, pre);
        fun1(s, 0, 1);

        fun1(s, 0, 2);
        mydfs(s, pre);
        fun1(s, 0, 2);

        fun1(s, 1, 2);
        mydfs(s, pre);
        fun1(s, 1, 2);

        fun1(s, 0, 3);
        mydfs(s, pre);
        fun1(s, 0, 3);
    }
    int flipLights(int n, int presses) {
        string s(n, '1');
        mydfs(s, min(4, presses));
        return ms.size();
    }
};
// @lc code=end
// 2\n1\n


class Solution {
public:
    int flipLights(int n, int presses) {
        if (presses > 2 && n > 2) return 8;
        if (n < 3) return 1 + (presses > 0) * n + (presses > 1 && n > 1);
        else return 1 + 3 * presses;
    }
};