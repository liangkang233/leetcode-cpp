// https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// 妙啊 维护两个堆 一个存储左区间 一个存储右区间
class Solution {
private:
    priority_queue<int, vector<int>, less<int>> L;      // 大根堆
    priority_queue<int, vector<int>, greater<int>> R;   // 小根堆
public:
    void Insert(int num) {
        L.push(num);
        if(L.size() == R.size() + 2) { // 左区间过长 移动该数据
            R.push(L.top());
            L.pop();
        } else if(!R.empty() && L.top() > R.top()) { // 交换左右边界数据
            int l1 = L.top(), l2 = R.top();
            L.pop(), R.pop();
            L.push(l2), R.push(l1);
        }
    }
    double GetMedian() {
        if(L.size() > R.size()) 
            return L.top();
        else {
            return (L.top() + R.top()) / (double)2;
        }
    }
};