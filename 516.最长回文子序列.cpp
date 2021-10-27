/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 题目5的扩展   子序列可删除

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<vector<int>> myarray(len, vector<int>(len, 0));
        for (int i = len-1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (i == j)
                    myarray[i][j] = 1;
                else if (s[i] == s[j]) 
                    myarray[i][j] = myarray[i+1][j-1]+2;
                else
                    myarray[i][j] = max(myarray[i+1][j], myarray[i][j-1]);
            }
        }
        return myarray[0][len-1];
    }
};
// @lc code=end

    // 压缩至一维  遍历的顺序要换下
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<int> myarray(len, 1);
        for (int j = 0; j <len; j++) {
            int yuanIJ = 0;
            myarray[j] = 1;
            for (int i = j-1; i >= 0; i--) {
                int temp = myarray[i];
                if(s[i] == s[j])
                    myarray[i] = yuanIJ + 2;
                else 
                    myarray[i] = max(myarray[i+1], myarray[i]);
                yuanIJ = temp;
            }
        }
        return myarray[0];
    }