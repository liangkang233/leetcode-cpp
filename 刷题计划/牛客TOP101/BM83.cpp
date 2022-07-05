// https://www.nowcoder.com/practice/c3120c1c1bc44ad986259c0cf0f0b80e?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string trans(string s, int n) {
        int l = 0;
        for (int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                reverse(s.begin() + l, s.begin() + i);
                l = i+1;
            } else {
                if(s[i] >= 'a')
                    s[i] -= 'a' - 'A';
                else
                    s[i] += 'a' - 'A';
            }
        }
        reverse(s.begin() + l, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};