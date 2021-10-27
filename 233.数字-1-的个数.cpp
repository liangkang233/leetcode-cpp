/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        long long M = 1, ans = 0; // M为10^k M可能会越界。需要设置为long long
        while (n >= M) {
            // ans += n/M/10 * M + min(M, n%(M*10)-M + 1);      // 注意 n%(M*10)-M 可能小于0
            ans += (n/M/10 + 1) * M + min(M, max(n%(M*10)-M + 1, 0LL)); // 0LL 表示为longlong类型的0，否则max参数不匹配
            M *= 10;
        }
        return ans;
    }
};
// @lc code=end

    int countDigitOne(int n) {
        // mulk 表示 10^k
        // 在下面的代码中，可以发现 k 并没有被直接使用到（都是使用 10^k）
        // 但为了让代码看起来更加直观，这里保留了 k
        long long mulk = 1;
        int ans = 0;
        for (int k = 0; n >= mulk; ++k) {
            ans += (n / (mulk * 10)) * mulk + min(max(n % (mulk * 10) - mulk + 1, 0LL), mulk);
            mulk *= 10;
        }
        return ans;
    }

/* 官方上面的写法非常简洁 另外这种解法也很巧妙
https://leetcode-cn.com/problems/number-of-digit-one/solution/gong-shi-tui-dao-qiu-mei-yi-wei-shang-1d-5qvu/
从低往高位，计算每一位的数量：
第1位上的1有：1+(n-1)/10
第2位上的1有：(1+(n/10-1)/10) * 10
第3位上的1有：(1+(n/100-1)/10) * 100
……
第k+1位上的1有：(1+(n/(10^k)-1)/10)*(10^k)
如果n的第k+1位上是1，则说明可能没有填满该位，计算第k+1位的数量时还要 -10^k+1+n%(10^k)，相当于独立计算
 */
    int countDigitOne(int n) {
        int m = 1;
        int ans = 0;
        while (n >= m){
            ans += (1+(n/m-1)/10)*m;
            if (n/m%10 == 1) ans = ans-m+1+n%m;
            m *= 10;
        }
        return ans;
    }