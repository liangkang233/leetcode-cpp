/*
 * @lc app=leetcode.cn id=522 lang=cpp
 *
 * [522] 最长特殊序列 II
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    // 由之前521题的经验,只有相同长度的字串全部相等。
    // 且符合 长度较小的一定是长度较大的子集才会返回-1。
    // 不妨以长度逆序排序后，最长的不相等 return 最长。
    // 向后遍历 穷举是否为子集 输出
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        auto isson = [](string a, string b) -> bool { // 判断b是否为a子集
            if(b.size() > a.size())
                return false;
            int j = 0;
            for (int i = 0; i < a.size() && j < b.size(); i++) {
                if(a[i] == b[j])
                    j++;
            }
            return j == b.size();
        };
        sort(strs.begin(), strs.end(), [](string a, string b) -> bool {return a.size() > b.size();}); //按照长度逆序排序
        for (int i = 0; i < strs.size(); i++) {
            ans = strs[i].size();
            for (int j = 0; j < strs.size(); j++) {
                if(i == j) //排除跟自身比较
                    continue;
                if(isson(strs[j], strs[i])){ // 判断 遍历值i 是否为其他字符的子集
                    ans = -1;
                    break;
                }
            }
            if(ans != -1) //停止遍历 后面的字符串长度小于等于它没必要比了
                return ans;
        }
        return -1;
    }
};
// @lc code=end

// ["qwe","qwer","qwert"]\n
// ["aabbcc", "aabbcc","c"]\n
// ["aabbcc", "aabbcc" ,"cb"] \n