/*
 * @lc app=leetcode.cn id=1598 lang=cpp
 *
 * [1598] 文件夹操作日志搜集器
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int path = 0;
        for (int i = 0; i < logs.size(); i++) {
            if(logs[i] == "../") {
                path = max(0, path-1);
            } else if(logs[i] == "./") {
                continue;
            } else {
                path++;
            }
        }
        return path;
    }
};
// @lc code=end

