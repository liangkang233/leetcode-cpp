/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

// @lc code=start
class Solution {
public:
    // 下面的两次判断都忘了加等号 被坑了..
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator it = nums.end() - 1, it1 = it;
        while (it!=nums.begin() && *(it-1)>=*(it)) // 倒序找到第一个 倒序 非递增 的数
            it--;
        if(it != nums.begin()) {    // it为容器首元素说明字典序最大 直接倒序输出
            while (*(it-1) >= *it1) // 倒序找到后半部分 第一个大于it的值 交换后 逆序后半部分即为下一字典序
                it1--;
            swap(*it1, *(it-1));    // 容器元素swap用法 v1.swap(v2)用于容器交换 等价swap(v1, v2) 新标准推荐使用后者
        }
        reverse(it, nums.end());
    }
};
// @lc code=end

// [1,5,1]\n