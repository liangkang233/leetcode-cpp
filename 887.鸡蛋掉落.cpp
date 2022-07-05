/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

#include <iostream>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    // 李永乐视频解析 https://www.bilibili.com/video/BV1KE41137PK
    // 1 <= k <= 100  所以下面的动态规划用100个做一组
    // 1 <= n <= 10^4
    unordered_map<int, int> memo;// 此处动态规划将 二维数组 转为 无序哈希表；memo(n*100 + k) => memo[n][k]
    int dp(int k, int n) {
        if (memo.find(n * 100 + k) == memo.end()) {
            int ans;
            if (n == 0) //楼层无 设定该值为0
                ans = 0;
            else if (k == 1) //仅剩1个蛋，必须从最低层遍历
                ans = n;
            else {
                int lo = 1, hi = n;
                while (lo + 1 < hi) { //二分查找，得出当前状态 k n下，最小的 大值dp
                    int x = (lo + hi) / 2;
                    int t1 = dp(k - 1, x - 1);// 摔碎了，向低的半边 x-1 个查找的dp
                    int t2 = dp(k, n - x);// 没摔碎，向高的半边 n-x个 查找的dp
                    if (t1 < t2)    //如果t1<t2 说明该X点在极小值点左边，示意图看这个 https://leetcode-cn.com/problems/super-egg-drop/solution/ji-dan-diao-luo-by-leetcode-solution-2/
                        lo = x;
                    else if (t1 > t2)
                        hi = x;
                    else
                        lo = hi = x;
                }
                // 二分到最后lo与hi相邻时还要再做一次判断大小，取出二分点为lo还是hi（取较小的）
                ans = 1 + min(max(dp(k - 1, lo - 1), dp(k, n - lo)), max(dp(k - 1, hi - 1), dp(k, n - hi)));
            }
            memo[n * 100 + k] = ans;
        }
        return memo[n * 100 + k];
    }

    int superEggDrop(int k, int n) {
        return dp(k, n);
    }
};
// @lc code=end

    //法2逆向思维 https://leetcode-cn.com/problems/super-egg-drop/solution/ji-dan-diao-luo-by-leetcode-solution-2/

    // 使用二分法没有充分考虑蛋的可重复性
    int superEggDrop(int k, int n) {
        // 当蛋的个数满足log(n)，足够二分。
        // 否则直到只剩最后一个蛋时由下往上搜寻破碎层f  k-1 + 剩余层数
        // 为了找到最小次数，每次都得对最坏情况(蛋碎)做处理
        int l=0, temp=n;
        while ( temp != 0) {
            l++;
            temp = temp >> 1;
        }
        if( k >= l)
            return l;
        else {
            temp = n, l = k;
            while ( l > 1) {
                l--;
                temp = temp >> 1;
            }
            cout << "shen " << temp << endl;
            return k - 2 + temp;
        }
    }

// 思路
//     反过来想这个问题：如果我们可以做 t 次操作，而且有 k 个鸡蛋，那么我们能找到答案的最高的 n 是多少？
//     我们设 f(t,k) 为在k个鸡蛋尝试t次最多能判断 f(t,k) 层楼。
//     如果我们求出了所有的 f(t,k)，那么只需要找出最小的满足 f(t, k) ≥ n 的 t。
//     那么我们如何求出 f(t, k) 呢？我们还是使用动态规划。因为我们需要找出最高的 n，
//     因此我们不必思考到底在哪里扔这个鸡蛋，我们只需要扔出一个鸡蛋，看看到底发生了什么：
//        如果鸡蛋没有碎，那么对应的是 f(t−1,k)，也就是说在这一层的上方可以有 f(t−1,k) 层；
//        如果鸡蛋碎了，那么对应的是 f(t−1,k−1)，也就是说在这一层的下方可以有 f(t−1,k−1) 层。
//     因此我们就可以写出状态转移方程：
//          f(t, k) = 1 + f(t-1, k-1) + f(t-1, k)
// 边界条件为：当 t≥1 的时候 f(t,1)=t，当 k≥1 时，f(1,k)=1。
// 那么问题来了：t 最大可以达到多少？由于我们在进行动态规划时，t 在题目中并没有给出，
// 那么我们需要进行到动态规划的哪一步呢？可以发现，操作次数是一定不会超过楼层数的，因此 t≤n，
// 我们只要算出在 f(n,k) 内的所有 f 值即可。
class Solution {
public:
    int superEggDrop(int k, int n) {
        if (n == 1) {
            return 1;
        }
        vector<vector<int>> f(n + 1, vector<int>(k + 1));
        for (int i = 1; i <= k; ++i) {
            f[1][i] = 1;
        }
        int ans = -1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                f[i][j] = 1 + f[i - 1][j - 1] + f[i - 1][j];
            }
            if (f[i][k] >= n) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};


class Solution {
public:
    // 我们设 i个鸡蛋尝试j次 最多能判断 f(i,j) 层楼。
    int superEggDrop(int k, int n) {
        if(k == 1) return n;
        else if(n == 1) return 1;
        vector<vector<int>> dp(k+1, vector<int>(n+1, 1)); // 置多操作n次
        for (int j = 1; j <= n; j++) dp[1][j] = j; // 1个鸡蛋操作j次最多获取j层  i个鸡蛋 操作1次最多获取1层
        // 为了 求最小次数 应该遍历 j 操作次数 再遍历鸡蛋
        for (int j = 2; j <= n; j++) { // i个鸡蛋 t次操作  
            for (int i = 2; i <= k; i++) {
                // 扔任意层 可知 当前楼层 + 蛋没碎最多获取dp[i][j-1]层 + 蛋碎最多获取dp[i-1][j-1]层
                dp[i][j] = 1 + dp[i][j-1] + dp[i-1][j-1];
                // if(dp[i][j] >= n)
                if(dp[i][j] >= n)
                    return j;
            }
        }
        return -1;
    }
};
// 3\n14
// 2\n1\n