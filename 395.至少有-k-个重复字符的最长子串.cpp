/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
// 想不到 可以用分治来做 
class Solution {
public:
    int mydfs(const string& s, int l, int r, int k) {
        if(r - l + 1 < k)   return 0;
        int a[26] = {0};
        for (int i = l; i <= r; i++) a[s[i] - 'a']++;
        char split = '0'; // 找寻该字串中第一个不满足的字符 按照该字符切割
        for (int i = 0; i < 26; i++) {
            if(a[i] != 0 && a[i] < k) {
                split = 'a' + i;
                break;
            }
        }
        // cout << split << endl;
        if(split == '0') return r -l + 1; // 该子串符合条件
        int ans = 0;
        while (l <= r) {
            int start = l;
            while (start <= r && s[start]==split)
                start++;
            if(start > r)
                break;
            int end = start;
            while (end <= r && s[end]!=split)
                end++;
            // cout << start << " " << end-1 << endl;
            ans = max(ans, mydfs(s, start, end-1, k));
            l = end;
        }
        return ans;
    }
    int longestSubstring(string s, int k) {
        return mydfs(s, 0, s.size()-1, k);
    }
};
// @lc code=end

// 官解的滑动窗口就离谱 https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/solution/zhi-shao-you-kge-zhong-fu-zi-fu-de-zui-c-o6ww/
class Solution {
public:
    int longestSubstring(string s, int k) {
        int M = 0;
        if(k == 1) return s.size();
        for (int N = 1; N <= 26; N++) { // N 为当前窗口至多种类
            int l = 0, r = 0, count = 0, need = 0; // 左右边界 当前窗口包含的种类数 还剩多少种类未完成
            int a[26] = {0};
            for (; r < s.size() && s.size()-l > M; r++) { // 长度不够时直接退出
                if(a[s[r]-'a'] == 0) {
                    count++;
                    need++;
                } else if (a[s[r]-'a'] == k-1) {
                    need--;
                }
                a[s[r]-'a']++;
                while(count > N) { // 移动左界
                    if(a[s[l]-'a'] == k) {
                        need++;
                    } else if(a[s[l]-'a'] == 1) {
                        count--;
                        need--;
                    }
                    a[s[l++]-'a']--;
                }
                if(need == 0) M = max(r-l+1, M); // 符合长度时 进入判断
            }
        }
        return M;
    }
};