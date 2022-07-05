/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool mydfs(vector<int>& s, vector<vector<int>>& edage, int i) {
        if(s[i] == 2)   return true;
        if(s[i] == 1)   return false;
        s[i] = 1;
        for (int j = 0; j < edage[i].size(); j++) {
            if(!mydfs(s, edage, edage[i][j]))
                return false;
        }
        s[i] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> s(numCourses, 0); // 0 代表 未扫描到 1 代表扫描中 2 扫描完毕
        vector<vector<int>> edage(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
            edage[prerequisites[i][1]].push_back(prerequisites[i][0]);
        for (int i = 0; i < numCourses; i++) {
            if(!mydfs(s, edage, i))
                return false;
        }
        for (int i = 0; i < numCourses; i++)
            if(s[i] != 2) return false;
        return true;
    }
};
// @lc code=end

