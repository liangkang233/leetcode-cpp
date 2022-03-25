#include <iostream>
#include <string>
using namespace std;

const int Maxn = 1024;

class Solution {
public:
    int next[Maxn] = { 0 }; //维护p等价前缀长度的记录数组,p匹配失败就跳转到该位置 即匹配了p的个数-1

    // 关键在于计算next数组 这里基于最大长度表(字符串的前缀后缀的公共元素的最大长度)来做
    // next数组是除当前字符外的最长相同前缀后缀。所以为最大长度表向右移一位，初值赋为-1的数组
    void GetNextval(string p) {
        next[0] = -1;
        int i = -1, j = 0; //p[i]表示前缀
        while (j < (p.size()) - 1) {
            if (i == -1 || p[i] == p[j]) {
                ++i;
                ++j;
                // next[j] = i; //优化如下所示, 当p[i] == p[j] 时，KmpSearch里不匹配调用next会重复调用，所以这里直接处理
                if(p[i] != p[j])
                    next[j] = i;
                else
                    next[j] = next[i];
            }
            else
                i = next[i];
        }
    }

    int KmpSearch(string s, string p) {
        int i = 0, j = 0;
        GetNextval(p);
        // 注意！ size() 返回的是无符号数，一定要转为有符号的  否则j为-1时会先转变为无符号数比较大小会错误
        while ( i < int(s.size()) && j < int(p.size()) ) {
            // j为-1 或 匹配成功 s、p的下标都向后走
            if (j == -1 || s[i] == p[j]) {
                i++;
                j++;
            }
            // 否则字符匹配失败，i不变 j转为next记录值，再用原来的 s[i] 与新的 p[j] 匹配
            // 当j==-1即该字符前不可能有相同前后缀时 还不匹配 说明 i 需要+1  而j=0
            else
                j = next[j];
        }
        if (j == p.size())
            return i - j;
        return -1;
    }
};

int main()
{
    Solution sol;
    string s1, s2;
    while (1) {
        cin >> s1 >> s2;
        cout << sol.KmpSearch(s1, s2) << endl;
    }
}