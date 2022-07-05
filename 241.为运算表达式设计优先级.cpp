/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;


// 递归分治，枚举最后一次计算的运算符。如果 expression[i] 是运算符，就将它的两侧进行递归，
// 拿到两侧能得到的所有结果再交叉组合，得到的就是以 i 位置的运算符为最后计算的步骤时，能够获得的所有可能结果。

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        for (int i = 0; i < expression.size(); i++) {
            if(expression[i] == '-' || expression[i] == '*' || expression[i] == '+') {
                vector<int> Larr = diffWaysToCompute(expression.substr(0, i));
                vector<int> Rarr = diffWaysToCompute(expression.substr(i+1, expression.size() - i - 1));
                for (int l = 0; l < Larr.size(); l++) {
                    for(int r = 0; r < Rarr.size(); r++) {
                        if(expression[i] == '+') {
                            ans.push_back(Larr[l] + Rarr[r]);
                        } else if(expression[i] == '-') {
                            ans.push_back(Larr[l] - Rarr[r]);
                        } else {
                            ans.push_back(Larr[l] * Rarr[r]);
                        }
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(expression));
        return ans;
    }
};
// @lc code=end
