/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        // 用char数组存储
        int max = INT_MIN;
        char max_char[10]={0} , ans[10] = {0};
        if (x >= 0) 
            max = INT_MAX; 
        
        int num = 0;
        for (; num < 10; num++) {
            ans[num] =  (x % 10);
            max_char[num] =  (max % 10);
            x /= 10;
            max /= 10;
            if ( !x ) break;
        }

        if (num == 9) {
            for (int i = num; i >= 0; i--) {
                if ( abs(ans[num - i]) > abs(max_char[i]) )
                    return 0;
                else if (ans[num - i] == max_char[i]) {
                    continue;
                }
                else 
                    break;
            }
        }

        int ansint=0;
        for (int i = 0; i <= num; i++) 
            ansint = ans[i] + 10 * ansint;
        return ansint;
    }
};
// @lc code=end

// 来看看官方的，自己写的真的蠢
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
                return 0;
            }
            int digit = x % 10;
            x /= 10;
            rev = rev * 10 + digit;
        }
        return rev;
    }
};



// 二刷 坑略多
class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        if(x < 0) { // x 为负数 不会溢出  由于题意 尾号最大为0 或 1
            flag = true;
            if(x == INT_MIN) return 0;
            x = -x;
        }
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        cout << s << endl;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            // if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] > '7'))
            if(ans > INT_MAX / 10)
                return 0;
            cout << s[i] << endl;
            ans = 10 * ans + (s[i] - '0');
        }
        return flag ? -ans : ans;
    }
};