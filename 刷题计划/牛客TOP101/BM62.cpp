// https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        int last = 0, now = 1, temp;
        for (int i = 1; i < n; i++) {
            temp = now;
            now += last;
            last = temp;
        }
        return now;
    }
};