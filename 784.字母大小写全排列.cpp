/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 'a'-'z' 97-122
// 'A'-'Z' 65-90
// '0'-'9' 48-57

// @lc code=start
class Solution {
public:
    const int add = 'a' - 'A'; 
    vector<string> ans;
    
    void next_permutation(string& s, int i) {
        if(i == s.size()) {
            ans.push_back(s);
            return;
        }
        if( s[i] > '9') {
            int flag = add;
            if (s[i] <= 'Z')
                flag = -flag;
            next_permutation(s, i+1); // 无变化
            s[i] -= flag;
            next_permutation(s, i+1); // 变化的
            s[i] += flag;//回溯
        }
        else
            next_permutation(s, i+1); //数字串不做处理
    }

    vector<string> letterCasePermutation(string s) {
        next_permutation(s, 0);
        return ans;
    }
};
// @lc code=end

