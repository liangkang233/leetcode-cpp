/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* 自实现的 lower_bound
int start = 0, end = nums.size()-1;
while (start < end) {
    int mid = start+end >> 1;
    if(nums[mid] < target)
        start = mid + 1;
    else 
        end = mid;
} */


// @lc code=start
class Solution {
public:
    // 以行首为目标二分 后对改行的列二分
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto row = [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];};
        auto it = upper_bound(matrix.begin(), matrix.end(), vector<int>{target}, row);
        int index = distance(matrix.begin(), it); // 以行首二分 寻找第一个大于 target 值  没找到返回的it为end
        index--;
        if(index < 0)
            return false;
        auto it1 = lower_bound(matrix[index].begin(), matrix[index].end(), target); // 对该行进行列的二分查找
        return it1 != matrix[index].end() && *it1 == target;
    }
};
// @lc code=end

// 如果行首一定大于上一行尾才可使用此法 否则要从最右边列开始二分查找 ./test_tools/二维二分法.cpp
// 以右上角启动 找到第一行为起始 使用upper 然后减一 删掉右边的列
// 然后对该列进行二分 找到upper减一的行 删掉上面的行 如此迭代

// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n60\n
// [[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n0\n
// [[1]]\n13\n
