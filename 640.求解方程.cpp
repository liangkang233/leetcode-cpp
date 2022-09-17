/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string solveEquation(string equation) {
        int x_count = 0, nums = 0, num = 0;
        char f = '+';
        bool flag = false;
        for(int i = 0; i < equation.size(); i++) {
            if(equation[i] == 'x' || equation[i] == '-' || equation[i] == '+' || i == equation.size()-1) {
                bool ff = f == '+';
                if(flag) ff = !ff;
                if(equation[i] == 'x') {
                    i++;
                    if(num == 0 && equation[i] != '0') num=1; // 居然会有 0x = 0 的案例
                    x_count += ff ? num : -num;
                } else {
                    if(equation[i] <= '9' && equation[i] >= '0') // 最后一位 添加数
                        num = num*10 + equation[i] - '0';
                    nums += ff ? num : -num;
                }
                f = equation[i];
                num = 0;
                // cout << x_count << "x + " << nums << " = 0" << endl;
            } else if(equation[i] == '=') {
                if(equation[i] != 'x') { // 当 = 前是数字说明才要处理之前残余的数字
                    nums += f == '+' ? num : -num;
                } 
                // cout << x_count << "x + " << nums << " = 0" << "   im ==" << endl;
                f = '+';
                flag = true;
                num = 0;
            } else {
                num = num*10 + equation[i] - '0';
            }
        }
        if(x_count == 0) {
            if(nums == 0)
                return "Infinite solutions";
            return "No solution";
        }
        return "x=" + to_string(-nums/x_count);
    }
};
// @lc code=end

// "x+5-3+x=6+x-2"
// "x=x"
// "2x=x"
// "2x+3x-6x=x+2"
// "x=x+2"
// "0x=0"
// "0x+0x=0x"