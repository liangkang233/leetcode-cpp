/*
 * @lc app=leetcode.cn id=1163 lang=cpp
 *
 * [1163] 按字典序排在最后的子串
 */

#include <iostream>
#include <string>

using namespace std;
// @lc code=start
class Solution {
public:
    string lastSubstring(string s) {
        string ans, ans1;
        int j = 1;
        char max = 'a' - 1;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] > max) {
                max = s[i];
                ans = s[i];
                ans1 = "";
            }
            else if( !ans1.empty() ) {
                if(ans1 == ans)
                ans1.push_back(s[i]);
                if(j >= ans.size() || ans[j] > s[i] || ans == ans1) {
                    // j >= ans.size() 不做处理会导致j内存越界 例如 "zzz" 返回 "zz"
                    // ans==ans1 (即ans1与ans相同需要拼接上ans) 如果不做处理会出现 测试案例cacacb 返回值为cacacb(正确返回cb)
                    copy(ans1.begin(), ans1.end(), back_inserter(ans));
                    ans1 = "";
                }
                else if(ans[j] < s[i]) {
                    ans = ans1;
                    ans1 = "";
                }
                j++;
            }
            else if(s[i] == max) {
                ans1 = s[i];
                j = 1;
            }
            else
                ans.push_back(s[i]);
        }
        copy(ans1.begin(), ans1.end(), back_inserter(ans));
        return ans;
    }
};
// @lc code=end
// "zzzzz"\n  -> zzzzz
// "ababc"\n -> c
// "zmzz"\n -> zz
// "cacacb"\n -> cb
// "zmkinezzwobllyxktqeibfoupcpptncggrdqbkji"\n -> "zzwobllyxktqeibfoupcpptncggrdqbkji"
