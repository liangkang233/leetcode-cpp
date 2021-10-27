/*
 * @lc app=leetcode.cn id=1935 lang=cpp
 *
 * [1935] 可以输入的最大单词数
 */

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    // 使用数组
    int canBeTypedWords(string text, string brokenLetters) {
        int ans = 0;
        char a='z';
        bool flag = false;  //是否有不能打的字母
        vector<int> myset('z'+1, 0);
        for (auto &&i : brokenLetters) 
            myset[i]++;
        for (auto &&i : text) {
            if (i == ' ') {
                ans += flag==true? 0 : 1;
                flag = false;
                continue;
            }
            if(myset[i] != 0)
                flag = true;
        }
        ans += flag==true? 0 : 1;// 不要忘了最后一个单词
        return ans;
    }
};
// @lc code=end

// 使用set
int canBeTypedWords(string text, string brokenLetters) {
    unordered_set<char> broken;   // 无法输入的字符集合
    for (char ch: brokenLetters){
        broken.insert(ch);
    }
    int res = 0;   // 可以完全输入的单词数目
    bool flag = true;   // 当前字符所在单词是否可被完全输入
    for (char ch: text){
        if (ch == ' '){
            // 当前字符为空格，检查上一个单词状态，更新数目并初始化 flag
            if (flag){
                ++res;
            }
            flag = true;
        }
        else if (broken.count(ch)){
            // 当前字符不可被输入，所在单词无法被完全输入，更新 flag
            flag = false;
        }
    }
    // 判断最后一个单词状态并更新数目
    if (flag){
        ++res;
    }
    return res;
}