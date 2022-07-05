// https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=295&tqId=23281&ru=%2Fpractice%2F8a19cbe657394eeaac2f6ea9b0f6fcf6&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


// 巧妙 只有 stack2 空了 才将stack1 全部倒灌 stack2中
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack1.empty() && stack2.empty())
            return -1;
        int node;
        if(stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        node = stack2.top();
        stack2.pop();
        return node;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};