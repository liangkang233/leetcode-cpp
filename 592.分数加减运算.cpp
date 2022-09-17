/*
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    long long gcd(long long a, long long b) {
        return b != 0 ? gcd(b, a % b) : a;
    }
    void myadd(pair<int, int>& ans, const pair<int, int>& now) {
        long long M = ans.second * now.second, m = ans.first * now.second + now.first * ans.second;
        long long a = gcd(abs(M), abs(m));
        ans.first = m / a;
        ans.second = M / a;
    }
    string fractionAddition(string expression) {
        bool flag = true;
        int i = 0, num = 0;
        if(!expression.empty() && expression[0] == '-') {
            flag = false;
            i = 1;
        }
        pair<int, int> ans{0, 1}, now(0, 1); // ans 初始值 0/1
        for(; i <= expression.size(); i++) {
            if(expression[i] == '+' || expression[i] == '-' || i == expression.size()) {
                now.second = num;
                num = 0;
                myadd(ans, now);
                flag = expression[i] == '+' ? true : false; // 这里越界会指向空字符 不会报错
            } else if(expression[i] == '/') {
                now.first = flag ? num : -num;
                num = 0;
            } else {
                num = 10 * num + (expression[i] - '0');
            }
        }
        return to_string(ans.first) + "/" + to_string(ans.second);
    }
};
// @lc code=end

