/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <iostream>
#include <set>
using namespace std;

// @lc code=start
class Solution {
public:
    // 使用数组下标做记录
    int lengthOfLongestSubstring(string s) {
        int head = 0, maxnum = 0, num = 0, len = s.size();
        char myset[127] = {0};
        for (int i = 0; i < len; i++) {
            if(myset[s[i]]) { // 说明有重复
                // 如果大于记录最大值则更新。更新，并删除非新头内容
                if(num > maxnum ) 
                    maxnum = num;
                while (s[head] != s[i])
                    myset[s[head++]]--;
                num = i - head;
                head++;
            }
            else {
                num ++;
                myset[s[i]]++;
            }
        }
        return num > maxnum ? num : maxnum; //防止max是默认值,或者没更新
    }
};

// @lc code=end

class Solution1 {
public:
    // set记录出现次数
    int lengthOfLongestSubstring(string s) {
        int head = 0, maxnum = 0, num = 0, len = s.size();
        set<char> myset;
        for (int i = 0; i < len; i++) {
            pair<set<char>::iterator, bool> ans = myset.emplace(s[i]);
            if(!ans.second) { // 插入失败，说明有重复值
                // 如果大于记录最大值则更新。更新，并删除非新头内容
                if(num > maxnum ) 
                    maxnum = num;
                while (s[head] != s[i])
                    myset.erase(s[head++]);
                num = i - head;
                head++;
            }
            else
                num ++;
        }
        return num > maxnum ? num : maxnum; //防止max是默认值,或者没更新
    }
};
