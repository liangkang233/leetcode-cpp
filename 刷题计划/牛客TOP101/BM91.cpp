// https://www.nowcoder.com/practice/c3a6afee325e472386a1c4eb1ef987f3?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串 
     * @return string字符串
     */
    string solve(string str) {
        for (int i = 0, j = str.size()-1; i < j; i++, j--) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
        return str;
    }
};