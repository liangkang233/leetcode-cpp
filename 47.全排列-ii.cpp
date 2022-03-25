/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 33/33 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 96.43 % of cpp submissions (8.2 MB)

// @lc code=start
class Solution {
public:
    bool mynext_permutation (vector<int>::iterator begin, vector<int>::iterator end) {
        // 使用双指针维护
        auto L = end-1, R = end-1;
        while( L != begin && *(L-1) >= *L ) // 从右边遍历查找第一个降序的点设为flag
            L--;
        if ( L == begin)  //全为升 即从左看全为降序,字典序排列完毕
            return false;
        while( R != L  && *R <= *(L-1) ) // 从L的右边遍历找到第一个大于(L-1)的点，不存在即转换L右边的点
            R--;
        swap(*R, *(L-1));
        // reverse(L, R+1);
        reverse(L, end);    //反转(L-1)后面整个排列
        return true;
    }

    // 参考编程之法的字符串字典序全排列
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{nums};
        while ( mynext_permutation(nums.begin(), nums.end()) )
            ans.push_back(nums);
        return ans;     
    }
};
// @lc code=end


// 使用 std 库的 next_permutation 函数    效果也很不错
// 33/33 cases passed (4 ms)
// Your runtime beats 93.92 % of cpp submissions
// Your memory usage beats 97.02 % of cpp submissions (8.1 MB)
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans{nums};
    while ( next_permutation(nums.begin(), nums.end()) )
        ans.push_back(nums);
    return ans;     
}


// 递归回溯 和90题一样去重思路 最后出来的结果就是字典序的
// visit 记录下标是否访问过 
class Solution {
public:
    void mydfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, vector<bool>& visit) {
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if(visit[i] || (i>0 && !visit[i-1] && nums[i-1]==nums[i])) // 剪枝 去重
                continue;
            temp.push_back(nums[i]);
            visit[i] = true;
            mydfs(ans, nums, temp, visit);
            temp.pop_back();
            visit[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> visit(nums.size(), false);
        vector<int> temp;
        sort(nums.begin(), nums.end());
        mydfs(ans, nums, temp, visit);
        return ans;
    }
};
// [1,2,3,4]\n
// [1,-3,-7,-2,5,9,4,-8]\n
