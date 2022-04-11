/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 乘法: 转换为 nums2 每个字符的 与num1乘法 之后相加 
    // 题目415 字符串相加
    string add (const string& num1, const string& num2) {
        string ans;
        char flag = 0;
        for (int i=num1.size()-1, j=num2.size()-1; i>=0 || j>=0 || flag>0; i--, j--) {
            char temp1 = 0, temp2 = 0;
            if(i >= 0)    temp1 = num1[i] - '0';
            if(j >= 0)    temp2 = num2[j] - '0';
            int temp = flag + temp1 + temp2;
            if(temp >= 10) {
                flag = 1;
                temp -= 10;
            }
            else
                flag = 0;
            ans.push_back(temp + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void multip (const string& num1, char b, string& ans) {
        if(num1 == "0" || b == '0') {
            ans = "0";
            return;
        }
        int bb = b - '0', flag = 0;
        for (int i = num1.size() - 1; i >= 0 || flag > 0; i--) {
            int temp1 = 0;
            if(i >= 0)    temp1 = num1[i] - '0';
            int temp = flag + temp1 * bb;
            if(temp >= 10) {
                flag = temp / 10;
                temp %= 10;
            }
            else
                flag = 0;
            ans.push_back(temp + '0');
        }
        reverse(ans.begin(), ans.end());
    }
    string multiply(string num1, string num2) {
        string ans = "0";
        if(num1 != "0" && num2 != "0") {
            for (int i = num2.size() - 1; i >= 0; i--) {
                string temp;
                multip(num1, num2[i], temp);
                if(temp != "0")
                    temp += string(num2.size() - 1 - i, '0');
                ans = add(ans, temp);
            }
        }
        return ans;
    }
};
// @lc code=end
// "0"\n"1123141"\n
// "1212312441323"\n"0"\n
// "120405050"\n"2340"\n
// "14346347362384578274897"\n"172638657871978718236786581237487684"\n
// "1412378589172587891237481675895781365871658793463473623845782723894758276348627863478562893547895672873467872734875823674897"\n"17263865787197871823672389475897248967893427689861278367891635786178236587189236758763124785581237487684"\n


// 官方用数组位来做，真不错
// 链接：https://leetcode-cn.com/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        auto ansArr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--) {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--) {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n) {
            ans.push_back(ansArr[index]);
            index++;
        }
        for (auto &c: ans) {
            c += '0';
        }
        return ans;
    }
};
