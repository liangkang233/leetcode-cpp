/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// @lc code=start
// 单调栈变形应用 元素小直接入栈 大于栈顶元素 出栈 记录两节点区间雨水
// 注意栈内只有一元素时 出栈入栈操作 无法接雨水 (两个边界无法接雨水)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, temp;
        stack<int> st; // 记录递减下标栈
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                temp = height[st.top()];
                st.pop();
                if(!st.empty()) {
                    int h = min(height[st.top()], height[i]) - temp;
                    ans += h * (i - st.top() - 1);
                }
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

// 动态规划 记录左侧最大值 右侧最大值 则该节点雨水能接两值较小值的差值
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        vector<int> L = height, R = height;
        for (int i = 1; i < n; i++) {
            L[i] = max(L[i-1], L[i]);
            R[n-i-1] = max(R[n-i], R[n-i-1]);
        }
        for (int i = 0; i < n; i++) {
            if(height[i] < min(L[i], R[i]))
                ans += min(L[i], R[i]) - height[i];
        }
        return ans;
    }
};


// 空间复杂度 n1 的双指针 即为将上动态规划方案优化
class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size()-1, ans = 0, ML = height[L], MR = height[R];
        while (L < R) {
            while (L < R && height[L] <= MR) {
                ans += min(ML, MR) - height[L];
                ML = max(ML, height[++L]);
            }
            while (L < R && height[R] <= ML) {
                ans += min(ML, MR) - height[R];
                MR = max(MR, height[--R]);
            }
        }
        return ans;
    }
};