/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        string ans(address.length() + 6, ' ');
        for (int i = 0, j = 0; i < address.size(); i++) {
            if(address[i] == '.') {
                ans[j++] = '[';
                ans[j++] = '.';
                ans[j++] = ']';
            } else
                ans[j++] = address[i];
        }
        return ans;
    }
};
// @lc code=end

