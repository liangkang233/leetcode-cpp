/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> ans(code);
        int sum = 0;
        auto getid = [&](int i) {
            return (i + code.size()) % code.size();
        };
        if(k == 0) {
            for (int i = 0; i < ans.size(); i++) ans[i]=0;
        } else if(k < 0) {
            k = -k;
            for (int i = code.size() - k; i < code.size(); i++)
                sum += code[i];
            ans[0] = sum;
            for(int i = 1; i < ans.size(); i++) {
                ans[i] = ans[i-1] - code[getid(i-1-k)] + code[i-1];
            }
        } else {
            for (int i = 1; i <= k; i++)
                sum += code[i];
            ans[0] = sum;
            for(int i = 1; i < ans.size(); i++) {
                ans[i] = ans[i-1] - code[i] + code[getid(i+k)];
            }
        }
        return ans;
    }
};
// @lc code=end

