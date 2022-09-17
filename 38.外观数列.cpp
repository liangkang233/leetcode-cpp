/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        string now = "1";
        for(int i = 1; i < n; i++) {
            string temp;
            int count = 1;
            for(int j = 1; j < now.size(); j++) {
                if(now[j] != now[j-1]) {
                    temp += to_string(count) + now[j-1];
                    count = 1;
                } else {
                    count++;
                }
            }
            temp += to_string(count) + now.back();
            now = temp;
        }
        return now;
    }
};
// @lc code=end

