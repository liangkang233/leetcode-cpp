/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    // 脑筋急转弯 遍历一遍找寻 合适的起点
    // 若 某 A-B 最后不可 说明 A-B 中皆不可为起点 直接继续在 B+1 后遍历即可
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i < n; i++) {
            int now = gas[i] - cost[i], count = 0, j = i;
            while(now >= 0) {
                count++;
                if(count == n)
                    return i;
                j = (j + 1) % n; 
                now += gas[j] - cost[j];
            }
            i += count; // 区间长为 count 的值都不能为起点 i 这里溢出 外面的for直接return
        }
        return -1;
    }
};
// @lc code=end

// 这写的也太优雅了
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total(0), subsum(INT_MAX), start(0);
        for(int i = 0; i < n; ++i) {
            total += gas[i] - cost[i];
            if(total < subsum) {
                subsum = total;
                start  = i + 1;
            }
        }
        return (total < 0) ?  -1 : (start % n); 
    }
};