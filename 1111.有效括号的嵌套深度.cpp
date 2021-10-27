/*
 * @lc app=leetcode.cn id=1111 lang=cpp
 *
 * [1111] 有效括号的嵌套深度
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        vector<int> ans;
        for(char str : seq) {
            if(str == '(') {
                depth++;
                ans.push_back(depth % 2);
            }
            else {
                ans.push_back(depth % 2);
                depth--;
            }
        }
        return ans;
    }
};
// @lc code=end

