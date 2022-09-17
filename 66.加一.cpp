/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = true;
        vector<int> ans{1};
        for (int i = digits.size()-1; i >= 0 && flag; i--) {
            digits[i]++;
            if(digits[i] == 10) {
                digits[i] = 0;
            } else {
                flag = false;
            }
        }
        if(flag) {
            ans.insert(ans.end(), digits.begin(), digits.end());
            return ans;
        } return digits;
    }
};
// @lc code=end

