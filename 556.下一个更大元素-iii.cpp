/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    // 全排列
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int l = s.size()-1, r = l;
        while (l > 0 && s[l-1] >= s[l]) l--;
        if(l == 0) return -1; // 该序列最大值
        while (s[r] <= s[l-1]) r--;
        // cout << s[l] << " " << s[r] << endl;
        swap(s[l-1], s[r]);
        reverse(s.begin()+l, s.end());
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if((ans > INT_MAX/10) || (ans==INT_MAX/10 && s[i] > '7'))
                return -1;
            ans = 10 * ans + (s[i] - '0'); // 这里不加括号会溢出 泔
        }
        return ans;
    }
};
// @lc code=end
// 123\n3245465\n547567\n34537\n23426567\n567687\n14346\n
// 2147483486\n2147483476\n
