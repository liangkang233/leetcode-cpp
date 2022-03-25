/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int a[26] = {0}, count = 0; // a数组 记录当前窗口还需要哪些字符
        for (int i = 0; i < p.size(); i++)
            a[p[i] - 'a']++;
        for (int i = 0, j = 0; i < s.size(); i++) { // 建立一个 由 j-i 的窗口
            a[s[i] - 'a']--;
            count++;
            if(a[s[i] - 'a'] < 0) { //该字符 不存在或过长 需要缩减窗口
                while (j <= i && a[s[i] - 'a'] < 0) {
                    a[s[j] - 'a']++;
                    j++;
                    count--;
                }
            }
            if(count == p.size()) {
                ans.push_back(j);
                a[s[j] - 'a']++;
                j++;
                count--;
            }
        }
        return ans;
    }
};
// @lc code=end

// ""aba"\n"ab"\n"
// ""abasukdfhkajvhuyaewqjklajdskljhakjnsahsjdhjnxjababjdbvughuwbabafbiuageiwhfjkhab"\n"b"\n"
// ""abasukdfhkajvhuyaewqjklajdskljhakjnsahsjdhjnxjababjdbvughuwbabafbiuageiwhfjkhab"\n"ab"\n"