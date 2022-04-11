/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 巧妙，动态规划的题还是做少了

/* 对于一个区间 [l,r][l,r]，我们可以维护四个量：
lSum 表示 [l,r] 内以 ll 为左端点的最大子段和
rSum 表示 [l,r] 内以 rr 为右端点的最大子段和
mSum 表示 [l,r] 内的最大子段和
iSum 表示 [l,r] 的区间和
以下简称 [l,m] 为 [l,r] 的「左子区间」，[m+1,r] 为 [l,r]的「右子区间」。
我们考虑如何维护这些量呢（如何通过左右子区间的信息合并得到 [l,r] 的信息）？
对于长度为 1 的区间 [i,i]，四个量的值都和 nums[i] 相等。

对于长度大于1的区间：
首先最好维护的是 iSum，区间 [l,r] 的 iSum 
就等于「左子区间」的 iSum 加上「右子区间」的 iSum。
对于 [l,r] 的 lSum，存在两种可能，它要么等于「左子区间」的 lSum，
要么等于「左子区间」的 iSum 加上「右子区间」的 lSum，二者取大。
对于 [l,r] 的 rSum，同理，它要么等于「右子区间」的 rSum，
要么等于「右子区间」的 iSum 加上「左子区间」的 rSum，二者取大。
当计算好上面的三个量之后，就很好计算 [l,r] 的 mSum 了。
我们可以考虑 [l,r] 的 mSum 对应的区间是否跨越 mm——它可能不跨越 mm，
也就是说 [l,r] 的 mSum 可能是「左子区间」的 mSum 和 「右子区间」的 mSum 中的一个；
它也可能跨越 mm，可能是「左子区间」的 rSum 和 「右子区间」的 lSum 求和。三者取大。
 */
// @lc code=start
class Solution {
public:
    struct status{
        // 以左 右区间为节点的最大值，整个区间的最大值、累加值
        int Lsum, Rsum, Msum, Asum;
        status(): Lsum(0), Rsum(0), Msum(0), Asum(0) {}
        status(int a, int b, int c, int d) :Lsum(a), Rsum(b), Msum(c), Asum(d) {}
    };
    
    status merge(status lsub, status rsub) {
        int a = max(lsub.Lsum, lsub.Asum + rsub.Lsum);
        int b = max(rsub.Rsum, lsub.Rsum + rsub.Asum);
        int c = max(max(lsub.Msum, rsub.Msum), lsub.Rsum + rsub.Lsum);  //关键
        int d = lsub.Asum + rsub.Asum;
        return status(a, b, c, d);
    }

    status get(vector<int>& nums, int l, int r) {
        if (l == r) 
            return status(nums[l],nums[l],nums[l],nums[l]);
        int mid = (l + r) / 2; 
        status lsub = get (nums, l, mid);
        status rsub = get (nums, mid + 1, r);
        return merge(lsub, rsub);
    }

    // 二分法 线段树
    int maxSubArray(vector<int>& nums) {
        int N = nums.size() - 1;
            return get(nums, 0, N).Msum;
    }
};
// @lc code=end


// 可以压缩为空间复杂度O(1)
class Solution1 {
public:
    // 动态规划 O(n), 仅仅维护以第i个数结尾的数组而不是 维护第x个至第y个的数组
    // 即maps[i]代表以i结尾的子数组最大长度
    // maps[i]可以优化为单个数字，空间复杂度O(1)
    int maxSubArray(vector<int>& nums) {
        int N = nums.size(), maxn = nums[0];
        vector <int> maps(N,0);
        maps[0] = nums[0];
        for (int i = 1; i < N; i++) {
            maps[i] = max( maps[i-1]+nums[i], nums[i] );
            if (maxn < maps[i])
                maxn = maps[i];
        }
        return maxn;
    }
};