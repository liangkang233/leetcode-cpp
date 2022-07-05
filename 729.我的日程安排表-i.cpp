/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */

#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 偷懒 直接红黑树 做法
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
// ["MyCalendar","book","book","book","book","book","book","book","book","book","book"]\n[[],[47,50],[33,41],[39,45],[33,42],[25,32],[26,35],[19,25],[3,8],[8,13],[18,27]]\n


// 二刷 使用容器区间 记录未使用的时间进行切割 效率跟map时间上差不多 空间节省些
class MyCalendar {
private:
    vector<pair<int, int>> time; // 区间对应 可以使用的时间段
public:
    MyCalendar() {
        time.push_back(pair<int, int>{0, 1e9+1});
    }
    bool book(int start, int end) {
        auto mycmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool  {
            return a.first < b.first;};
        auto it = upper_bound(time.begin(), time.end(), make_pair(start, end), mycmp);
        if(it == time.begin() || end > (it-1)->second)
            return false;
        it--;
        if(it->first == start && it->second == end) {
            time.erase(it);
        } else if(it->first == start) {
            it->first = end;
        } else if(it->second == end) {
            it->second = start;
        } else { // it 在删除 增加元素后会失效
            int L = it->first;
            it->first = end;
            time.insert(it, make_pair(L, start));
        }
        // for (int i = 0; i < time.size(); i++)
        //     cout << time[i].first << ":" << time[i].second << " ";
        // cout << endl;
        return true;
    }
};
