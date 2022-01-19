/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        ans.reserve(max(a.size(), b.size()) + 1);
        char temp = 0;
        int index_a = a.size()-1, index_b = b.size()-1;
        while (index_a >= 0 || index_b >= 0 || temp > 0) {
            char ta = index_a<0 ? '0' : a[index_a--];
            char tb = index_b<0 ? '0' : b[index_b--];
            char i = temp + ta + tb - '0';
            temp = 0;
            if(i >= '2') {
                temp = 1;
                i -= 2;
            }
            ans.push_back(i);
        }
        reverse(ans.begin(), ans.end());
        return  ans;
    }
};
// @lc code=end

// "1"\n"101"\n
// "111"\n"101"\n