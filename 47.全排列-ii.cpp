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
        while( R != L  && *R <= *(L-1) ) // 从L的右边遍历找到第一个大于flag的点，不存在即转换L右边的点
            R--;
        swap(*R, *(L-1));
        // reverse(L, R+1);
        reverse(L, end);    //反转后面整个排列
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