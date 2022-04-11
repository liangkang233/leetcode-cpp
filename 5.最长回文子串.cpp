/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    //动态规划
    string longestPalindrome(string s) {
        int len = s.length(), begin = 0, max = 1;
        if (len < 2)    return s;
        vector<vector<bool>> myarray(len, vector<bool>(len, true));
        for (int i = len-1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                // 将i>j 的非法情况默认用true填充，然后以 j>=x 遍历可以节省一次比较判断：例如
                // if (i == j) myarray[i][j] = true;
                // else if( j == i + 1)
                //     myarray[i][j] = s[i] == s[j];
                // else 
                myarray[i][j] = myarray[i+1][j-1] && s[i] == s[j];
                if (myarray[i][j] && j-i+1 > max) {
                    max = j-i+1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, max);
    }
};
// @lc code=end

// 中心扩散
/* 可以发现，所有的状态在转移的时候的可能性都是唯一的。也就是说，我们可以从每一种边界情况开始「扩展」，也可以得出所有的状态对应的答案。
边界情况即为子串长度为 1 或 2 的情况。我们枚举每一种边界情况，并从对应的子串开始不断地向两边扩展。如果两边的字母相同，我们就可以继续扩展
，例如从 P(i+1,j-1)P(i+1,j−1) 扩展到 P(i,j)P(i,j)；如果两边的字母不同，我们就可以停止扩展，因为在这之后的子串都不能是回文串了。
「边界情况」对应的子串实际上就是我们「扩展」出的回文串的「回文中心」。方法二的本质即为：我们枚举所有的「回文中心」并尝试「扩展」，
直到无法扩展为止，此时的回文串长度即为此「回文中心」下的最长回文串长度。我们对所有的长度求出最大值，即可得到最终的答案。 */

class Solution {
public:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};


// 二刷 节省空间的做法 压缩为1维
class Solution {
public:
    string longestPalindrome(string s) {
        int maxi = 0, count = 1;
        // vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), true));
        vector<bool> dp(s.size(), true), temp(dp); //dp[j] 表示 i -> j 是否为回文 temp[j] 表示 i+1 -> j 是否为回文
        for (int i = s.size()-2; i >= 0; i--) {
            for (int j = i+1; j < s.size(); j++) {
                if(temp[j-1] && s[i] == s[j]) {
                    dp[j] = true;
                    if(j-i+1 > count) {
                        maxi = i;
                        count = j-i+1;
                    }
                }
                else 
                    dp[j] = false;
            }
            swap(dp, temp);
        }
        return s.substr(maxi, count);
    }
};
// @lc code=end
// "asdjghajkhjkhsjadhfjaaaaaaaaaaaaaaoooooooooooooppppppppppsssshgjfkah"\n
// "asdjghajkhjabccbaagffgfgfgfgfyuttyuioppoiuytytyuioppoiuythgjfkah"\n
// "a"\n

// 三刷
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 1, index = 0;
        // vector<vector<bool>> dp(n, vector<bool>(n, true)); // i j 相等默认为true
        vector<bool> dp(n, true), temp(dp); // 优化为一维 代表上一行尾部为j-1的记录 temp为当前行即尾部为j的记录
        for (int j = 1; j < n; j++) { // i 为头 j 为尾
            for (int i = j-1; i >= 0; i--) {
                if(s[i]==s[j] && dp[i+1]) {
                    temp[i] = true;
                    if(j-i+1 > maxLen) {
                        maxLen = j-i+1;
                        index = i;
                    }
                }
                else
                    temp[i] = false;
            }
            swap(dp, temp);
        }
        return s.substr(index, maxLen);
    }
};