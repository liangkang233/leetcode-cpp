/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int ans = 0, temp = 0;
        vector<int> record(s.size(), 0);
        record.back() = s.back() == '1' ? 1 : 0;
        for (int i = s.size()-2; i >= 0; i--)
            record[i] = record[i+1] + (s[i] == '1' ? 1 : 0);
        for(int i = 0; i < s.size() - 1; i++) {
            temp += s[i] == '0' ? 1 : 0;
            // cout << i << " " << temp << " " << record[i+1] << endl;
            ans = max(temp+record[i+1], ans);
        }
        return ans;
    }
};
// @lc code=end
// "00"\n"011101"\n"00111"\n"1111"\n