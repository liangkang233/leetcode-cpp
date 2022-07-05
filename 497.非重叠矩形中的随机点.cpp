/*
 * @lc app=leetcode.cn id=497 lang=cpp
 *
 * [497] 非重叠矩形中的随机点
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
private:
int sum = 0;
vector<int> area;
vector<vector<int>> _rects;
public:
    Solution(vector<vector<int>>& rects) : _rects(rects) {
        for (int i = 0; i < rects.size(); i++) {
            // 注意面积点数需要加1 !!!
            sum += (rects[i][3] - rects[i][1] + 1) * (rects[i][2] - rects[i][0] + 1);
            area.push_back(sum);
        }
    }
    // 需要按照每个矩形的面积加权取随机值 确定矩形后再确定随机点
    vector<int> pick() {
        int k = distance(area.begin(), upper_bound(area.begin(), area.end(), rand() % sum));
        int x = rand() % (_rects[k][2] - _rects[k][0] + 1) + _rects[k][0];
        int y = rand() % (_rects[k][3] - _rects[k][1] + 1) + _rects[k][1];
        return vector<int>{x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
// @lc code=end

