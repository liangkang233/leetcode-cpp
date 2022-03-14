/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

#include <iostream>
#include <vector>
#include <string>
#include <regex>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> myfun(string a){
        vector<int> b = {0, 0};
        sscanf(a.c_str(), "%d+%di", &b[0], &b[1]);
        return b;
    }
    string myfun1(int a, int b) {
        char temp[16];
        sprintf(temp, "%d+%ii", a, b);
        return string(temp);
    }
    string complexNumberMultiply(string num1, string num2) {
        auto a1 = myfun(num1);
        auto a2 = myfun(num2);
        // cout << a1[0] <<" " <<a1[1] << endl;
        // cout << a2[0] <<" " <<a2[1] << endl;
        return myfun1(a1[0]*a2[0]-a1[1]*a2[1], a1[1]*a2[0]+a1[0]*a2[1]);
    }
};
// @lc code=end

// "1+-1i"\n"1+1i"\n
// "1+-1i"\n"1+-1i"\n

// 切割法
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int pos1 = num1.find('+');
        int pos2 = num2.find('+');
        int a1 = stoi(num1.substr(0, pos1)), b1 = stoi(num1.substr(pos1+1, num1.size()-pos1-2));
        int a2 = stoi(num2.substr(0, pos2)), b2 = stoi(num2.substr(pos2+1, num2.size()-pos2-2));
        int a = a1 * a2 - b1 * b2;
        int b = a1 * b2 + b1 * a2;
        string ans = to_string(a) + "+" + to_string(b) + "i";
        return ans;
    }
};

// 官方的 正则表达式
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        regex re("\\+|i"); 
        vector<string> complex1(sregex_token_iterator(num1.begin(), num1.end(), re, -1), std::sregex_token_iterator());
        vector<string> complex2(sregex_token_iterator(num2.begin(), num2.end(), re, -1), std::sregex_token_iterator());
        int real1 = stoi(complex1[0]);
        int imag1 = stoi(complex1[1]);
        int real2 = stoi(complex2[0]);
        int imag2 = stoi(complex2[1]);
        return to_string(real1 * real2 - imag1 * imag2) + "+" + to_string(real1 * imag2 + imag1 * real2) + "i";
    }
};


// c使用切割 strtok 
bool parseComplexNumber(const char * num, int * real, int * image) {
    char *token = strtok(num, "+");
    *real = atoi(token);
    token = strtok(NULL, "i");
    *image = atoi(token);
    return true;
};

char * complexNumberMultiply(char * num1, char * num2){
    int real1 = 0, imag1 = 0;
    int real2 = 0, imag2 = 0;
    char * res = (char *)malloc(sizeof(char) * 20);
    parseComplexNumber(num1, &real1, &imag1);
    parseComplexNumber(num2, &real2, &imag2);
    snprintf(res, 20, "%d+%di", real1 * real2 - imag1 * imag2, real1 * imag2 + imag1 * real2);
    return res;
}
