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
    // 1 <= k <= 100
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
                    if (t1 < t2)
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

