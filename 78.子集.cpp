/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 法1 将数据位拆成二进制来计算，求二进制下的每一数位
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size(), maxn = 1;
        for (int i = 0; i < len; i++)
            maxn *= 2;
        // 上循环可以写成 maxn = 1 << len
        // vector<vector<int>> ans(maxn, vector<int> temp);
        vector<vector<int>> ans(maxn);
        for (int i = 0; i < maxn; i++) {
            int temp = i, j = 0;
            do {
                if(temp & 1)
                    ans[i].push_back(nums[j]);
                // temp /= 2;
                temp = temp >> 1;
                j++;
            } while (temp > 0);
        }
        return ans;
    }

    // 法2 dfs 回溯 将每种可能递归出来
    void dfs(int cur, vector<int>& nums, vector<int>& t, vector<vector<int>>& ans) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums, t, ans);
        t.pop_back();
        dfs(cur + 1, nums, t, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        dfs(0, nums, t, ans);
        return ans;
    }
};
// @lc code=end

// 官方写的法1, 的确是比我写的简洁
class Solution1 {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};


// 二刷
class Solution {
public:
    // 法1 将数据位拆成二进制来计算，求二进制下的每一数位
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for (int i = 0; i < 1<<nums.size(); i++) {
            vector<int> temp;
            for (int j = 0; j<nums.size(); j++) {
                if(i & 1<<j)
                    temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }

    // 法2 dfs 回溯
    vector<vector<int>> ans;
    void mydfs(vector<int>& nums, vector<int>& temp, int index) {
        if(index >= nums.size()) {
            ans.push_back(temp);
            return;
        }
        mydfs(nums, temp, index+1);
        temp.push_back(nums[index]);
        mydfs(nums, temp, index+1);
        temp.pop_back();
    }
    vector<vector<int>> subsets2(vector<int>& nums) {
        vector<int> temp;
        mydfs(nums, temp, 0);
        return ans;
    }

};