/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int isok(vector<int>& piles, int mid) { // mid 是当前速度
        int nums = distance(piles.begin(), upper_bound(piles.begin(), piles.end(), mid)), index = nums;
        for (int i = index; i < piles.size(); i++)
            nums +=  (piles[i] + mid -1) / mid; // 向上取余
        return nums;
    }
    // 求最小的k  k越大时间越少 即为求 LR中第一个满足 nums <= h 的速度
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int L = 1, R = piles.back(), nums = L;
        while (L < R) {
            int mid = (L + R) / 2;
            nums = isok(piles, mid);
            if(nums > h)
                L = mid + 1;
            else
                R = mid;
        }
        return L;
    }
};
// @lc code=end

// [312884470]\n312884469
// [30,11,23,4,20]\n6
// [3,4,5,23,30,234,567]\n12
// [30,11,23,4,20,1,24,235,34,65,4,7,658,5,754,6,54,6,54,7,568,5,68,54,67,54,78,56,8,567,46,57,56,7]\n45


// 二刷 不如第一次的速度快 一刷求时间值可以采用二分加快计算 效果不如二刷
// 此解法在超出需求h前就退出
class Solution {
public:
    bool vaild (int v, const vector<int>& piles, int h) {
        int t = 0;
        for (int i = 0; i < piles.size(); i++) {
            t += (piles[i] + v -1) / v ; // 向上取余
            if(t > h)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int M = 0, m = 1;
        for (int i = 0; i < piles.size(); i++)
            M = max(M, piles[i]);        
        // 二分法 v至多为最大值 v至小为1
        while (m < M) {
            int mid = (m + M) / 2;
            if(!vaild(mid, piles, h))
                m = mid + 1;
            else 
                M = mid;
        }
        return m;
    }
};