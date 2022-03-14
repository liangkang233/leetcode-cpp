/*
 * @lc app=leetcode.cn id=2100 lang=cpp
 *
 * [2100] 适合打劫银行的日子
 */

#include <vector>
#include <iostream>
using namespace std;


// Your runtime beats 78.92 % of cpp submissions
// Your memory usage beats 6.59 % of cpp submissions (88.4 MB)
// @lc code=start
class Solution {
public:
    // 贪心 直接找出并记录所有满足时间的长度递减和递增下标 重合时间下标即为适合打劫的日子
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> ans, increase, decrease;
        int temp = 0; //temp1表示当前下标递增或递减长度
        for (int i = 0; i < security.size(); i++) {
            temp++;
            if(i == 0 || security[i] > security[i-1])
                temp = 0;
            if(temp >= time)
                increase.push_back(i);
        }
        for (int i = security.size() - 1; i >= 0; i--) {
            temp++;
            if(i == security.size()-1 || security[i] > security[i+1])
                temp = 0;
            if(temp >= time)
                decrease.push_back(i);
        } // 合并有效日期 increase的值对应的下标是递增的 decrease的值递减所以反过来
        for (int i = 0, j = decrease.size()-1; i < increase.size() && j >= 0; i++, j--) {
            if(increase[i] > decrease[j])
                i--;
            else if(increase[i] < decrease[j])
                j++;
            else
                ans.push_back(increase[i]);
        }
        return ans;
    }
};
// @lc code=end

// time 可以为 0 我是没想到的，坑 初始的i==0 i==size-1要考虑
// [1, 1, 1, 1, 1]\n0
// [1, 2, 3, 4, 5, 6]\n2

// 官方动态规划
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
            if (security[n - i - 1] <= security[n - i]) {
                right[n - i - 1] = right[n - i] + 1;
            }
        }
        vector<int> ans;
        for (int i = time; i < n - time; i++) {
            if (left[i] >= time && right[i] >= time) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

// 大佬双指针 思路类似 正向标记出前 time 天符合条件的日期，逆向遍历选出前后都符合的加入答案
// 直接对security动手脚做标志位 省空间 还少一次合并循环
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> ans;
        int rear = -1, n = security.size(), cnt = 1;
        for(int i = 0; i < n; ++i){
            int x = security[i];
            rear>=x ? ++cnt : cnt = 1;
            if(cnt > time) security[i] ^= (1<<30);
                rear = x;
        }
        rear = -1, cnt = 0;
        for(int i = n-1; i >= 0; --i){
            int x = security[i] &~ (1<<30);
            rear>=x ? ++cnt : cnt = 1;
            if(cnt > time && (security[i] >> 30)) ans.push_back(i);
                rear = x;
        }
        return ans;
    }
};