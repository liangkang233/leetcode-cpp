/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
// 动态规划 需要删减数量
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, word1.size()+word2.size()));
        for (int i = 1; i <= word1.size(); i++) {
            for(int j = 1; j <= word2.size(); j++) {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1] - 2;
                else {
                    dp[i][j] = min(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp.back().back();
    }
};
// @lc code=end
// ""qwer"\n"qw"\n"
// ""letcode"\n"etde"\n"
// ""asdgkhiqauwheojhasoidgjhikahsdkgjhajsdhgkjhajsdghoiawhklnxdcmkvbnauhidgcuyghsdjkhqwaer"\n"asasdjhgjkahgsdkhkawjhdgiohjakjsdhgkjoiweuuihwjkfhasjkdhgjhasjkdhgkjahkjlfghajkshdgjkdf"\n"


// 计算最长公共子序列 dp[i][j]即为 text1 长度为i, text2 长度为j 的最长公共子序列 的长度
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));
        for (int i = 1; i <= word1.size(); i++) {
            for(int j = 1; j <= word2.size(); j++) {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return word1.size() + word2.size() - 2 * dp.back().back();
    }
};

// 题意理解错 不一定要连续的删减
class Solution {
public:
    bool kmp(string str1, string str2) {
        vector<int> next(str2.size(), -1);
        for (int i = -1, j = 1; j < str2.size(); j++) {
            while (i!=-1 && str2[i+1] != str2[j]) i = next[i];
            if(str2[i+1] == str2[j])
                i++;
            next[j] = i;
        }
        for (int i = -1, j = 0; j < str1.size(); j++) {
            while (i!=-1 && str2[i+1] != str1[j]) i = next[i];
            if(str2[i+1] == str1[j])
                i++;
            if(i == str2.size() - 1)
                return true;
        }
        return false;
    }
    int minDistance(string word1, string word2) {
        if(word1.size() < word2.size())
            swap(word1, word2);
        // 挑选str2的子串序列 在str1中进行kmp
        for (int len = word2.size(); len > 0; len--) { // len 等于0 时直接不做kmp word1 word2 不存在相同元素
            for (int i = 0; (i+len) <= word2.size(); i++) { // 以len为长度 i为首字符的字串进行kmp
                cout << word2.substr(i, len) << endl;
                if( kmp(word1, word2.substr(i, len)) ) { // 进行kmp对比 若找到必为最大子串
                    cout << word2.substr(i, len) << " " << word1.size() + word2.size() << " " << len << endl;
                    return word1.size() + word2.size() - 2 * len;
                }
            }
        }
        return word1.size() + word2.size();
    }
};