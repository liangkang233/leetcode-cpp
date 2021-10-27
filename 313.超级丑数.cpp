/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

#include <istream>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    // 使用254题目的方法进行改进 动态规划
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> dp(n, 1), factors(m, 0);
        for (int i = 1; i < n; i++) {
            int num=INT_MAX;
            for (int j = 0; j < m; j++) {
                if (num > dp[factors[j]] * primes[j])
                    num = dp[factors[j]] * primes[j];
            }
            dp[i]=num;
            for (int j = 0; j < m; j++) {
                if (num == dp[factors[j]] * primes[j])
                    factors[j]++;
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

class Solution {
public:
    // 使用254题目的方法进行改进 堆（优先队列）
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        unordered_set<int> myset{1};
        priority_queue<long long, vector<long long>, greater<long long>> myqueue;
        myqueue.push(1);
        int ans;
        for (int i = 0; i < n; i++) {
            long temp = myqueue.top();
            myqueue.pop();
            ans = int (temp);
            for (auto prime : primes) {
                // if ( myset.find(prime*temp) == myset.end() ) {
                //     myset.insert(prime*temp);
                //     myqueue.push(prime*temp);
                // }  // 先查再插会超时

                // 很不幸，这样也会超时，但是官方这么写的，就很怪
                if ( myset.insert(prime*temp).second ) { //插入成功说明没有重复
                    myqueue.push(prime*temp);
                }
            }
        }
        return ans;
    }
};