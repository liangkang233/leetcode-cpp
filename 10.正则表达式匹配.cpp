/*
 * @lc app=leetcode.cn id=10 lang=cpp
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * [10] 正则表达式匹配
 */

// 官方的动态规划解法
// https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-by-leetcode-solution/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.size(), pl = p.size();
        vector<vector<int>> f_map;
        f_map.assign(sl + 1, vector<int>(pl + 1, 0));
        f_map[0][0] = 1;
        // p为正则表达式字符串

        // 匿名函数用法  这样做可减少内存的拷贝
        auto matches = [&](int i, int j) -> bool{
            if(i == 0)
                return false;
            else if(p[j - 1] == '.')
                return true;
            else
                return s[i - 1] == p[j - 1];
        };

        for (int i = 0; i <= sl; i++) {         // i j代表第几个字符，若为0 表示字符为空
            for (int j = 1; j <= pl; j++) {     // j为0时除非i=0否则必定匹配失败,初始化时已经给所有除f_map[0][0]外赋0
                if(p[j-1] == '*') {
                    if( matches(i, j-1) )
                        // f_map[i][j] = f_map[i-1][j];         i-1表示*复制一份前字符，j-2表示*和之前字符代表空
                        f_map[i][j] = f_map[i-1][j] || f_map[i][j-2]; //加上或，防止当前s头不能减少的情况
                    else
                        f_map[i][j] = f_map[i][j-2];        // 
                }
                else{
                    if( matches(i, j) ) 
                        f_map[i][j] = f_map[i-1][j-1];
                }
            }
        }
        return f_map[sl][pl];
    }
};
// @lc code=end