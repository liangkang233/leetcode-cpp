// https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=295&tqId=23268&ru=%2Fpractice%2F54275ddae22f475981afa2244dd448c6&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
private:
    stack<int> st1, st2;
public:
    void push(int value) {
        st1.push(value);
        if(st2.empty() || st2.top() >= value)
            st2.push(value);
    }
    void pop() {
        if(st1.empty()) return;
        int val = st1.top();
        st1.pop();
        if(val == st2.top())
            st2.pop();
    }
    int top() {
        return st1.empty() ? -1 : st1.top();
    }
    int min() {
        return st2.empty() ? -1 : st2.top();
    }
};