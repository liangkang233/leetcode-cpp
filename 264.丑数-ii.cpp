/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
// 定义三个指针表示下一个丑数是当前指针指向的丑数乘以对应的质因数。初始时，三个指针的值都是dp[1]。
// 相当于3个数组，分别是能被2、3、5整除的递增数组，且每个数组的第一个数都为1。
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++) {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = min(min(num2, num3), num5);
            if (dp[i] == num2) {
                p2++;
            }
            if (dp[i] == num3) {
                p3++;
            }
            if (dp[i] == num5) {
                p5++;
            }
        }
        return dp[n];
    }
};
// @lc code=end

//直接用两个容器 动态规划会超时，需要优化下（因为取余等操作很费时间，下面用乘法的都比这快多了）
    int nthUglyNumber(int n) {
        vector<int> uglynum(n,1);
        vector<bool> myarray(1, false);
        myarray.push_back(true);
        
        auto mytest = [&](int i, int x)->bool{return i%x==0 && myarray[i/x];};
        for (int i = 2, num = 1; num < n; i++) {
            if(mytest(i, 2) || mytest(i, 3) || mytest(i, 5) ) {
                myarray.push_back(true);
                // cout << i << " " << num << endl;
                uglynum[num++] = i;
            }
            else 
                myarray.push_back(false);
        }
        return uglynum[n-1];
    }

// 使用优先队列的（堆）  set去重
    int nthUglyNumber(int n) {
        vector<int> factors = {2, 3, 5};
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        seen.insert(1L);
        heap.push(1L);
        int ugly = 0;
        for (int i = 0; i < n; i++) {
            long curr = heap.top();
            heap.pop();
            ugly = (int)curr;
            for (int factor : factors) {
                long next = curr * factor;
                if (!seen.count(next)) {
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }
        return ugly;
    }
