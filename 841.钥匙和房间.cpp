/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    int nums = 1;
    void mydfs(vector<vector<int>>& rooms, int index, vector<bool>& record) {
        for (int i = 0; i < rooms[index].size(); i++) {
            int j = rooms[index][i];
            if(!record[j]) { // 只有没开过的房间递归 防止死循环 剪枝
                nums++;
                record[j] = true;
                mydfs(rooms, j, record);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> record(rooms.size(), false);
        record[0] = true;
        mydfs(rooms, 0, record);
        return nums == rooms.size();
    }
};
// @lc code=end

// [[1,3],[3,0,1],[2],[0]]