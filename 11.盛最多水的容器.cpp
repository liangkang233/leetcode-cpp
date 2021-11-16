/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
// area = min(height[i], height[j]) * (j - i) 
// 使用两个指针，值小的指针向内移动，这样就减小了搜索空间 
// 因为面积取决于指针的距离与值小的值乘积，如果值大的值向内移动，距离一定减小，
// 而求面积的另外一个乘数一定小于等于值小的值，因此面积一定减小，而我们要求最大的面积，
// 因此值大的指针不动，而值小的指针向内移动遍历
    int maxArea(vector<int>& height) {
        int ans = 0, i = 0, j = height.size()-1;
        while(i < j) {
            ans =  max( min(height[i], height[j]) * (j - i), ans);
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};
// @lc code=end

    // 暴力法会超时
    int maxArea(vector<int>& height) {
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i+1; j < height.size(); j++) {
                ans = max( min(height[i], height[j]) * (j - i), ans);
            }
        }
        return ans;
    }