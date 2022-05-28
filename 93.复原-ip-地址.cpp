/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<string> ans;
public:
    void mydfs(string& s, vector<int> temp, int k) {
        if (temp.size() == 4 && k == s.size()) {
            string a = to_string(temp[0]);
            for (int i = 1; i < 4; i++)
                a += '.' + to_string(temp[i]);
            ans.push_back(a);
        } else if (temp.size() < 4) {
            for (int i = 1; i <= 3 && k+i <= s.size(); i++) { // i代表当前串长度
                if(i > 1 && s[k] == '0') break; // 前导0非法
                string t = s.substr(k, i);
                // cout << k << " " << i << " " << t << endl;
                int T = stoi(t);
                if(T <= 255) {
                    temp.push_back(T);
                    mydfs(s, temp, k+i);
                    temp.pop_back();
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() <= 12) {
            vector<int> temp;
            mydfs(s, temp, 0);
        }
        return ans;
    }
};
// @lc code=end
// "0000"\n
// "101023"\n
// "1121141223"\n