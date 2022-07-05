// https://www.nowcoder.com/practice/11ae12e8c6fe48f883cad618c2e81475?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算两个数之和
     * @param s string字符串 表示第一个整数
     * @param t string字符串 表示第二个整数
     * @return string字符串
     */
    string solve(string s, string t) {
        string ans(max(s.size(), t.size())+1, '0');
        int l1 = s.size()-1, l2 = t.size()-1, l3 = 0, temp = 0;
        while (l1 >= 0 || l2 >= 0 || temp > 0) {
            int a1 = 0, a2 = 0;
            if(l1 >= 0) a1 = s[l1--] - '0';
            if(l2 >= 0) a2 = t[l2--] - '0';
            ans[l3++] += (a1 + a2 + temp) % 10;
            temp = (a1 + a2 + temp) / 10;
        }
        if (ans.back() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};