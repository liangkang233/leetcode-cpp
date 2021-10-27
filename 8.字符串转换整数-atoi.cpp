/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

// 未使用long long参考 题7 做法
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        bool flag = true;
        int ans=0, fu = 1;
        for (auto &&str : s){
            if( str >= '0' && str <= '9' ) {
                flag = false;
                if (ans == INT_MAX /10 && str-'0' > 7) 
                    return INT_MAX;
                else if (ans == INT_MIN /10 && str-'0' > 8)
                    return INT_MIN;
                else if (ans > INT_MAX /10 || ans < INT_MIN /10)
                    return ans > 0 ? INT_MAX : INT_MIN;
                ans = ans*10 + fu * (str - '0');
            }
            else {
                if (flag && (str == '-' || str == '+')) {
                    if (str == '-')
                        fu = -1;
                    flag = false;
                }
                else if (flag && str ==' ')
                    continue;
                else
                    return ans;
            }
        }
        return ans;
    }
};
// @lc code=end


// 状态机做法
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' || c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};