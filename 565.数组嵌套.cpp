/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
// 效果很差
class Solution {
public:
    int mydfs(unordered_set<int>& ms, vector<int>& nums, int index) {
        if(ms.find(index) != ms.end()) // 出现重复元素 到达最深递归
            return 0;
        ms.insert(index);
        return 1 + mydfs(ms, nums, nums[index]);
    }
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> ms; // 下标对应的最大递归长度 不同的元素 出现环代表这些元素不用遍历了，其长度就是这个环
        for (int i = 0; i < nums.size(); i++) {
            if(ms.find(nums[i]) == ms.end())
                ans = max(mydfs(ms, nums, nums[i]), ans);
        }
        return ans;
    }
};
// @lc code=end


// 原地标记也太快了
class Solution {
public:
    int arrayNesting(vector<int> &nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            while (nums[i] < n) {
                int num = nums[i];
                nums[i] = n;
                i = num;
                ++cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

// 简历vis标记遍历
class Solution {
public:
    int arrayNesting(vector<int> &nums) {
        int ans = 0, n = nums.size();
        vector<int> vis(n);
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            while (!vis[i]) {
                vis[i] = true;
                i = nums[i];
                ++cnt;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};