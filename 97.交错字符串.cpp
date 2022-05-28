/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) { // 题意 s1 s2 长度相差1
        if(s1.empty())
            return s2==s3;
        if(s2.empty())
            return s1==s3;
        if(s1.size() + s2.size() != s3.size())
            return false;
        // vector<int> record{0}; // 记录当前遍历s3长度 符合为交错字符串的 s2符合的长度
        unordered_set<int> record; // 改用set 以免元素重复 超时
        record.insert(0);
        for (int i = 0; i < s3.size(); i++) {
            unordered_set<int> temp;
            cout << i << endl;
            for (auto &&i : record) {
                cout << i << endl;
            }
            for (const int& j : record) {
                int k = i-j; // 当前s1下标
                if(s3[i] == s2[j])
                    temp.insert(j+1);
                if(s3[i] == s1[k])
                    temp.insert(j);
            }
            swap(temp, record);
        }
        return !record.empty();
    }
};
// @lc code=end

// ""aabcc"\n"dbbca"\n"aadbbbaccc""
// ""a"\n""\n"c""
// """\n"a"\n"a""
// ""\n""\n""\n
// ""cbcccbabbccbbcccbbbcabbbabcababbbbbbaccaccbabbaacbaabbbc"\n"abcbbcaababccacbaaaccbabaabbaaabcbababbcccbbabbbcbbb"\n"abcbcccbacbbbbccbcbcacacbbbbacabbbabbcacbcaabcbaaacbcbbbabbbaacacbbaaaabccbcbaabbbaaabbcccbcbabababbbcbbbcbb""


// 官方的优雅多了 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector <int> f(s2.size() + 1, false);
        int n = s1.size(), m = s2.size(), t = s3.size();
        if (n + m != t)
            return false;
        f[0] = true; // f[i][j] 表示 i长度s1 j长度s2 是否匹配s1+s3长度字符  压缩至一维
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[j] = f[j] && (s1[i - 1] == s3[p]);
                    // f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[j] = f[j] || (f[j - 1] && s2[j - 1] == s3[p]);
                    // f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return f[m];
    }
};

// 剑指offer
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector <bool> f(s2.size() + 1, false);
        int n = s1.size(), m = s2.size(), t = s3.size();
        if (n + m != t)
            return false;
        f[0] = true; // f[i][j] 表示 i长度s1 j长度s2 是否匹配s1+s3长度字符  压缩至一维
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                int k = i+j-1; // s3当前下标
                if(i > 0) {
                    f[j] = f[j] && (s1[i-1]==s3[k]);
                }
                if(j > 0) {
                    f[j] = f[j] || (f[j-1] && s2[j-1]==s3[k]);
                }
            }
        }
        return f[m];
    }
};