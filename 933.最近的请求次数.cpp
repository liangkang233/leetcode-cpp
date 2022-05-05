/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */

#include<queue>
using namespace std;

// @lc code=start
class RecentCounter {
private:
    queue<int> myque;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        myque.push(t);
        while (t > myque.front() + 3000)
            myque.pop();
        return myque.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end

