/*
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    // 用高中知识 向量积来做即可 https://zhuanlan.zhihu.com/p/91318694
    // 不判断长度相等有可能为 矩形非正方形
    bool myfun(vector<int>& p1, vector<int>& xy, vector<int>& p2) {
        int x1 = xy[0] - p1[0],  x2 = xy[0] - p2[0], y1 = xy[1] - p1[1], y2 = xy[1] - p2[1];
        return (x1 || y1) && (x2 || y2) && x1*x2 + y1*y2 == 0 && x1*x1 + y1*y1 == x2*x2 + y2*y2;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(myfun(p4, p1, p2)) {
            return myfun(p1, p2, p3) && myfun(p1, p4, p3);
        } else if(myfun(p3, p1, p2)) {
            return myfun(p1, p3, p4) && myfun(p1, p2, p4);
        } else if(myfun(p3, p1, p4)) {
            return myfun(p1, p3, p2) && myfun(p1, p4, p2);
        }
        return false;
    }
};
// @lc code=end

// [0,0]\n[5,0]\n[5,4]\n[0,4]\n