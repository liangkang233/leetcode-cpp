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

// 二刷 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, myset[127] = {0};
        for (int i = 0, j = 0; i < s.size(); i++) {
            if(myset[s[i]] > 0) {
                while (j <= i && myset[s[i]] > 0 ) {
                    myset[s[j++]] = 0;
                }
            }
            myset[s[i]] = 1;
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};

// 三刷 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l = 0;
        int set[127] = {0};
        for (int r = 0; r < s.size(); r++) {
            while (l < r && set[s[r]] > 0) {
                set[s[l++]]--;
            } set[s[r]]++;
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};