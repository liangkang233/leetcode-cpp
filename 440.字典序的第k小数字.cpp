/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

#include <iostream>
#include <algorithm>
using namespace std;

// https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/zi-dian-xu-de-di-kxiao-shu-zi-by-leetcod-bfy0/

// @lc code=start
class Solution {
public:
    // ans该字典树下 含有的节点数量n 即经过n-1步达到合法节点的最后一个 
    // 经过n步将离开ans节点子树到达ans字典层的相邻节点
    // 小心 ans 临时变量越界
    int maxnums(long long n, int ans)
    {
        long long L = ans, R = ans;
        int step = 0;
        while (L <= n) {
            step += R - L + 1;
            L *= 10;
            R = min(10*R+9, n);
        }
        return step;
    }
    int findKthNumber(int n, int k) {
        int ans = 1;
        k--;
        while (k > 0) {
            int step = maxnums(n, ans);
            if(step <= k) { // 该节点树下节点完全遍历也无法满足k，切换其他子树
                ans+=1;
                k -= step;
            }
            else {  // 所求k就在该子树下，深层递归下去
                ans *= 10;
                k--;
            }
        }
        return ans;
    }
};
// @lc code=end
// 681692778\n351251360