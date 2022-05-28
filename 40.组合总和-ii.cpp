/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 需要去重，采用90题子集II的思想 前一个元素未采用 且当前值相同需要添加时 跳过该此递归
// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    // curr 表示当前数组合, index 是当前下标, flag表示上一次递归采用了元素
    void mydfs(vector<int>& candidates, vector<int>& temp, int target, int curr, int index, bool flag) {
        if(target == curr) {
            ans.push_back(temp);
            return;
        }
        if (index >= candidates.size() || target < curr)
            return;
        // curr + candidates[index] > target) // 剪枝  flag || candidates[index-1]!=candidates[index] // 去重
        if((flag || candidates[index-1]!=candidates[index]) && (curr+candidates[index]<=target)) {
            temp.push_back(candidates[index]);
            mydfs(candidates, temp, target, curr + candidates[index], index+1, true); //添加当前元素
            temp.pop_back(); //回溯放弃当前元素
        }
        mydfs(candidates, temp, target, curr, index+1, false); //放弃当前元素
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        mydfs(candidates, temp, target, 0, 0, true);
        return ans;
    }
};
// @lc code=end
// [12,34,2,3,6,7]\n15
// [12,34,2,3,6,7,32,45,5,12]\n20
// [2]\n1
// [1]\n7


// 牛的 大佬的真的简洁
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    void backtrack(vector<int>& candidates, int target, int index)
    {
        if(target == 0) {
            res.push_back(temp);
            return;
        }
        for(int i = index; i < candidates.size() && target-candidates[i] >= 0; i++) {
            if(i > index && candidates[i] == candidates[i-1]) // 这个去重和上面效果是一样的 推荐这种写法
                continue;
            temp.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return res;
    }
};

// 二刷  这里还是没掌握到精髓 
// if(i > index && candidates[i] == candidates[index]) // 去重
// 应该写为 if(i > index && candidates[i] == candidates[i-1]) 就无需后面的第二个去重了
class Solution {
private:
    vector<vector<int>> ans;
public:
    void mydfs(vector<int>& candidates, vector<int>& temp, int index, int target) {
        if (target == 0) {
            ans.push_back(temp);
        } else {
            for (int i = index; i < candidates.size() && target-candidates[i] >= 0; i++) {
                if(i > index && candidates[i] == candidates[index]) // 去重
                    continue;
                temp.push_back(candidates[i]);
                // cout << candidates[i] << " ";
                mydfs(candidates, temp, i+1, target-candidates[i]);
                temp.pop_back();
                while (i+1 < candidates.size() && candidates[i+1] == candidates[i]) i++; // 相同元素只需对第一次出现的进行dfs 
                // 这一步相当于把当前不选的值相同的都删了 多次一举直接之前就continue
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        mydfs(candidates, temp, 0, target);
        return ans;
    }
};