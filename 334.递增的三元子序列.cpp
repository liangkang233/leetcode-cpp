/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int temp = nums[0], temp1 = temp; // 序列临时值 temp, temp1 递增序列
        int temp = nums[0], temp1 = INT_MAX; // 序列临时值 temp, temp1 递增序列
        // 注意temp1初始值 intmax 而不是nums[0], 即第1次初始化必须要有 否则例如 [5,1,6] 错误
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > temp) {
                if(nums[i] > temp1)
                    return true;
                temp1 = nums[i];
            }
            else
                temp = nums[i];
        }
        return false;
    }
};
// @lc code=end

// [5,4,3,2,1]\n
// [1,2,3,4,5]\n
// [1,5,2,3]\n
// [5,1,6]\n
// [0,4,2,1,0,-1,-3]\n
// [1,5,2,0,3]\n
// [5,1,5,5,2,5,4]\n



// 二刷 贪心遍历 维护 最小值 中间值
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX-1, mid = INT_MAX;     
        if(nums.size() >= 3) {
            for (int i = 0; i < nums.size(); i++) {
                // cout << i << " " << min << " " << mid << endl;
                if(nums[i] > mid)
                    return true;
                if(nums[i] <= min)
                    min = nums[i];
                else
                    mid = nums[i];
            }
        }
        return false;
    }
};

// 单调栈 不可应用在此题  例如 [1,5,2,0,3] 0 清空栈 不符合题意的错误情况
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size() >= 3) {
            stack<int> st;
            for (int i = 0; i < nums.size(); i++) {
                while (!st.empty() && st.top() > nums[i]) // 与top相等的元素直接pass
                    st.pop();
                if(st.empty() || nums[i] > st.top()) // 与top相等的元素直接pass
                    st.push(nums[i]);
                cout << st.size() << " " << st.top() << endl;
                if(st.size() >= 3)
                    return true;
            }
        }
        return false;
    }
};