/*
 * @lc app=leetcode.cn id=464 lang=cpp
 *
 * [464] 我能赢吗
 */

#include <iostream>
#include <vector>
using namespace std;

// 题目292扩展

// @lc code=start
class Solution {
public:
    // dp代表使用那些status位的数字后，再拿数字是否能赢 不讨论做这个操作的是谁
    vector<int> dp;
    int range = 0;

    bool dfs(int dest, int status) {
        if(dp[status] != -1)
            return dp[status]==1 ? true : false;
        for (int i = 1; i <= range; i++) {
            int temp = 1 << (i-1);
            // 注意： c++中 & 优先级小于 == !=
            if ( (status&temp) != 0) continue;
            if (i >= dest || !dfs(dest-i, status | temp) ) {
                dp[status] = 1;
                return true;
            }
        }
        dp[status] = 0;
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ( maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal )
            return false;
        // if ( maxChoosableInteger >= desiredTotal)
        //     return true;
        range = maxChoosableInteger;
        dp.resize(1 << maxChoosableInteger, -1); // -1表示为初始化，0为false 1为true
        return dfs(desiredTotal, 0);
    }
};
// @lc code=end


// 一个易懂的博弈解答（python） 空间 时间都是 2^n 
/* 特判：
如果最大能选择的数字maxChoosableInteger比期望的总数desiredTotal要大，先手稳赢，返回True
如果能选择的所有数字总和比期望的总数desiredTotal要小，一定到达不了desiredTotal，先手稳输，返回False

用二进制位来标记某个数是否已被选择，比如01表示1已被选择，10表示2已被选择，11表示1和2都被选择，100表示3被选择，
以此类推，1<<(n−1) 表示n这个数字被选择使用
n个数共有2 ^ n2 种被选择与否的状态(state)，比如2个数有4种状态：00、01、10、11，用长度为 2 ^ n
也就是1 << n的dp数组来存储这些状态(state)是否已经出现过，以及这些状态(state)对应是赢(True)还是输(False)
为什么需要记录已经出现过的状态，因为我们在递归的过程中可能会有重复的状态出现，比如对于1 - 5 五个数的选择，先手选了3，
后手选了5，剩下可选择的数为1,2,4；如果先手选了5，后手选了3，剩下可选择的数也是1,2,4。对于已经出现过的状态，
不需要重复计算，而是直接返回之前已经计算过的结果dp[state]就可以了

递归的参数有3个，分别是
当前所有数字被选择与否的状态：state
当前剩余需要到达的目标：desiredTotal
当前各个状态是否出现过以及其输赢情况：dp数组

每次进入递归时
先判断一下当前状态state是否已经出现过了，出现过就返回dp[state]，没有就继续往下计算
遍历能够被选择的所有整数（从1到maxChoosableInteger），当前数i对应的状态cur为1 << (i - 1)，
如果当前数i已经被选择cur & state != 0，
直接continue进入下一个数的选择，因为一个数只能选一次

如果当前数i比剩余要达到的目标desiredTotal要大，说明选了这个数以后游戏就结束了，
先手已赢，说明当前状态state可以让先手赢，dp[state] = True，并返回True

如果当前先手选了i之后还不能马上赢，但是下一步后手选数字的时候选输了
（也就是dfs(cur | state, desiredTotal - i, dp)返回了False），
说明先手能赢，dp[state] = True，并返回True

如果遍历完了所有的整数，当前state还没有返回过True，说明这种状态就不能让先手赢，dp[state] = False，并返回False

最后返回的就是第一层递归的结果，dfs(0, desiredTotal, [None] * (1 << maxChoosableInteger))，
也就是还没开始选择数字的时候（state为0时），能不能判断先手一定能赢
 */

/* 
class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if maxChoosableInteger >= desiredTotal: return True
        if (1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal: return False

        def dfs(state, desiredTotal, dp):
            if dp[state] != None:
                return dp[state]
            for i in range(1, maxChoosableInteger + 1):
                cur = 1 << (i - 1)
                if cur & state != 0:
                    continue
                
                if i >= desiredTotal or not dfs(cur | state, desiredTotal - i, dp):
                    dp[state] = True
                    return True
            dp[state] = False
            return False
        
        return dfs(0, desiredTotal, [None] * (1 << maxChoosableInteger)) 
*/