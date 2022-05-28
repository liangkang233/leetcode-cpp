/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

#include <map>
#include <iostream>
using namespace std;

// @lc code=start
class MyCalendar {
private:
    map<int, int> mymap; // key value 对应 日程 start 到 end
public:
    MyCalendar() {
    }
    bool book(int start, int end) {
        // 新加区间要在 it1尾部后 it头部前
         // map empty时 begin() == end()
        map<int, int>::iterator it = mymap.upper_bound(start), it1 = it;
        if(it != mymap.begin() && (--it1)->second > start) {
            return false;
        }
        if(it != mymap.end() && it->first < end) {
            return false;
        }


        mymap[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
// ["MyCalendar","book","book","book"]\n[[],[47,50],[33,41],[39,45]]\n