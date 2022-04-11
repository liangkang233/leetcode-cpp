/*
 * meituan-001. 小美的用户名
 *
 * https://leetcode-cn.com/problems/BaR9fy/
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ascii: 0-9 48-57, A-Z 65-90, a-z 97-122
bool myfun (const string& str) {
    // int num = 0, num1 = 0; // 对应字母 数字 个数
    int num1 = 0; // 对应 数字 字符个数
    if(!isalpha(str[0]))
        return false;
    for (int i = 1; i < str.size(); i++) {
        if(isalpha(str[i]))
            ;
        else if(str[i] <= 57 && str[i] >= 48)
            num1++;
        else
            return false;
    }
    return num1 > 0;
}

int main () {
    int T;
    cin >> T;
    // T = 5;
    // vector<string> test{"asjhui12h4", "1sfu1", "safj_fdhh", "dsaf23feg"};
    vector<string> test(T);
    for (int i = 0; i < T; i++)
        cin >> test[i];

    // for (auto &&i : test)
    //     cout << i << endl;
    for (int i = 0; i < T; i++) {
        if(myfun(test[i]))
            cout << "Accept" << endl;
        else
            cout << "Wrong" << endl;
    }
    
    return 0;
}