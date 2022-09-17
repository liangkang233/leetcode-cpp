// https://leetcode.cn/problems/coin-change/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 完全背包 最小代价问题 经典做法
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if(i-coins[j] < 0)
                    break;
                else if(dp[i-coins[j]] < 0)
                    continue;
                if(dp[i] == -1)
                    dp[i] = dp[i-coins[j]] + 1;
                else
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
            // cout << dp[i] << endl;
        }
        return dp[amount];
    }
};

// https://leetcode.cn/problems/combination-sum-iv/solution/zu-he-zong-he-iv-by-leetcode-solution-q8zv/
// 背包问题两层 for 循环， 一种是固定背包的大小，选元素，从少到多。 一种是固定元素的个数，循环背包大小，从小往大。 
// 在一个元素只能用一次的时候，两种 for 循环，谁在外层，其实看都一样能得到答案。但是在一个元素可以用两次的时候，可能就会出问题：
// 由下面这种先固定元素个数再循环背包大小就会出错 会少一部分答案 恰好为此题答案
// https://leetcode.cn/problems/coin-change-2/solution/ling-qian-dui-huan-ii-by-leetcode-soluti-f7uh/
func combinationSum4(nums []int, target int) int {
    dp := make([]int, target + 1)
    dp[0] = 1
    for _, v := range nums{
        for i := v; i<= target; i++{
            dp[i] += dp[i-v] 
        }
    }
    return dp[target]
}


// 将背包的大小固定，遍历元素就不会有错
func combinationSum4(nums []int, target int) int {
    dp := make([]int, target + 1)
    dp[0] = 1
    for i := 0; i <= target; i++{
        for _, v := range nums{
            if i >= v{
                dp[i] += dp[i-v]
            }
        }
    }
    return dp[target]
}

// 本质上是排列和组合的区别，当背包大小固定， 循环元素的时候，是按照排列的方式计数。而固定元素数量， 遍历背包大小的时候是组合。该
// 题的问题是有多少种情况，很显然，是一个排列问题。
// 以nums = [1,2,3]， target = 4举例:正确答案是: (1,1, 1,1)(1, 1,2)(1,2, 1)(1,3)(2, 1, 1)(2, 2)(3, 1)
// 但是固定元素数量，遍历背包的时候，只会出现 (1,1,2)。另外的 (2,1,1) 和 (1,2,1) 被视为同种情况   ** 相当于已经确定了元素的顺序 不会出现重复 **
// 为什么会出现这样的情况呢?

// 当固定元素的时候，遍历背包的时候，dp 记录的是当前元素及以前的排列，不包含后面元素的排列，例如在固定元素为1时，遍历结束背包容
// 量的时候，dp记录的是只有元素1的时候，背包从空到满的排列方式。当元素为2的时候，dpl[-v] 如果成立，实际上是先排列了1元素，然
// 后再排列了2。但是由于此时已经固定的元素是2，所以没办法查找dp[-元素1]的情况，即2, 1 这种排列方式漏掉了。
