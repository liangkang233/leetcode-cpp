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
// 二刷
// 长度较大的串 和 长度较小的串， 长度小的串 一定不是最长特殊序列
// 关键点在于 字符串集合中的 最长特殊序列一定是 集合中某个字符串
// 证明： 假设 strs[i] 的某个子串为特殊序列，则 strs[i] 一定也为特殊序列
// 所以， 长度越长 是特殊序列的可能性越大， 最长特殊序列如果存在 一定是集合中某个字符串
class Solution {
public:
    bool isMax (const string& a, const string& b) { // 判断 a 是否为 b 的子序列
        for (int i = 0, j = 0; i < b.size(); i++) {
            if(b[i] == a[j])
                j++;
            if(j == a.size())
                return true;
        }
        return false;
    }
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](const string& a, const string& b){return a.size() > b.size();});
        for (int i = 0; i < strs.size(); i++) {
            int size = strs[i].size(); // 假设 strs[i] 是最长特殊序列
            for (int j = 0; j < strs.size() && strs[i].size() <= strs[j].size(); j++) {
                // strs[i] 长度小于等于 strs[i] 时, 判断是否为strs[j]子序列。
                if(i == j)
                    continue;
                if(isMax(strs[i], strs[j])) {
                    size = -1;
                    break;
                }
            }
            if(size > 0)
                return size;
        }
        return -1;
    }
};
// @lc code=end
// ["qwe","qwer","qwert"]\n
// ["aabbcc", "aabbcc","c"]\n
// ["aabbcc", "aabbcc" ,"cb"] \n

class Solution {
public:
    // 由之前521题的经验,只有相同长度的字串全部相等。
    // 且符合 长度较小字符串 是 长度较大字符串的子集才会返回-1。
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