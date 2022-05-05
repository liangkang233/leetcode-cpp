/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 双指针遍历 左指针 右指针 皆二分查询增加 减少
        vector<int>::iterator L = numbers.begin(), R = numbers.end() - 1;
        while (L != R - 1) { //当二分到最后 找不到有效下标 即L与R相邻时 非target 输出-1表示找不到
            if(*L + *R == target)
                break;
            else if(*L + *R > target) { // 在 L+1 -> R-1 中二分寻找
                R = upper_bound(L + 1, R, target - *L) - 1;
            }
            else { // 在 L+1 -> R-1 中二分寻找
                L = lower_bound(L + 1, R, target - *R);
            }
        }
        return *L + *R != target ? vector<int>{-1, -1} : vector<int>{(int)distance(numbers.begin(), L)+1, (int)distance(numbers.begin(), R)+1};
    }
};
// @lc code=end

// [1,2,3,4,5,5,6,7,8,8,9,9,10,10,10,10,124,543]\n667
// [1,2,3]\n6