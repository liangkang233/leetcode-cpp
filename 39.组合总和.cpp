/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// dfs最好加个剪枝
// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    void mydfs(vector<int>& candidates, vector<int>& temp, int target, int curr, int index) {
        if(curr == target) // 超出的会提前break
            ans.push_back(temp);
        else {
            for (int i = index; i < candidates.size(); i++) {
                if(curr + candidates[i] > target) //candidates排序过 这里超出了后面必定超出
                    break;
                temp.push_back(candidates[i]);
                // cout << curr + candidates[i] << endl;
                mydfs(candidates, temp, target, curr + candidates[i], i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        mydfs(candidates, temp, target, 0, 0);
        return ans;
    }
};
// @lc code=end

// [12,34,2,3,6,7]\n15
// [12,34,2,3,6,7,32,45,65,120]\n20
// [2]\n1
// [1]\n7