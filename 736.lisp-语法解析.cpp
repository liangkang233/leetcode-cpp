/*
 * @lc app=leetcode.cn id=736 lang=cpp
 *
 * [736] Lisp 语法解析
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <sstream>
using namespace std;

// 放弃
// @lc code=start
class Solution {
public:
    int mydfs(string s, unordered_map<char, int> mp) {
        auto in = istringstream(s);
        string temp, temp1;
        in >> temp;
        int index = 0;
        if(temp == "let") {
            index += 3;
            in >> temp >> temp1;
            if(temp[0] == '(') {
                return mydfs(s.substr(index, s.size()-index), mp);
            } else if(temp1[0] == '(') {

            }

        }
        else if(temp == "add") {
            index += 3;

        } else {
            index += 4;

        }
        return 0;
    }
    int evaluate(string expression) {
        unordered_map<char, int> mp;
        return mydfs(expression.substr(1, expression.size()-1), mp);
    }
};
// @lc code=end

