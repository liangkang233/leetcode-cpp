/*
 * @lc app=leetcode.cn id=731 lang=cpp
 *
 * [731] 我的日程安排表 II
 */

#include <iostream>
#include <map>
using namespace std;

// 仍然使用 729 的map会很复杂，这里学习 https://leetcode.com/problems/meeting-rooms-ii/discuss/203658/HashMapTreeMap-resolves-Scheduling-Problem
// 使用 map 记录边界次数 左边界+1 右边界-1  这样遍历map时 某一段second和出现 大于 2 就代表同时出现三个及以上区间叠加
// @lc code=start
class MyCalendarTwo {
private:
    map<int, int> mp;
public:
    MyCalendarTwo() {}
    bool isok (int n) {
        int count = 0;
        for (auto && m : mp) {
            count += m.second;
            // cout << m.first << " " << m.second << " " << count << endl;
            if(count > n)
                return false;
        }
        return true;
    }
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        if(!isok(2)) {
            mp[start]--;
            mp[end]++;
            return false;
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

