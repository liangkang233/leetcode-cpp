/*
 * @lc app=leetcode.cn id=346 lang=cpp
 * 
 * https://leetcode-cn.com/problems/moving-average-from-data-stream/
 * 
 * https://leetcode-cn.com/problems/qIsx9U/
 * 
 * [346] 数据流中的移动平均值
 */

#include <queue>
#include <iostream>
using namespace std;

// @lc code=start
class MovingAverage {
private:
    int size, sum = 0;
    queue<int> myque;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        if(myque.size() == size) {
            sum -= myque.front();
            myque.pop();
        }
        sum += val;
        myque.push(val);
        return (double)sum / myque.size();
    }
};
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
// @lc code=end
