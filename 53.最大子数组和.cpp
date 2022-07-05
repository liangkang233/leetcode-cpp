#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
    // 动态规划 O(n), 仅仅维护以第i个数结尾的数组而不是 维护第x个至第y个的数组
    // 即maps[i]代表以i结尾的子数组最大长度
    int maxSubArray(vector<int>& nums) {
        int N = nums.size(), maxn = nums[0];
        vector<int> maps(N,0);
        maps[0] = nums[0];
        for (int i = 1; i < N; i++) {
            maps[i] = max( maps[i-1]+nums[i], nums[i] );
            if (maxn < maps[i])
                maxn = maps[i];
        }
        return maxn;
    }
};
// @lc code=end

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

// 二刷
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, now = 0;
        for(int i = 0; i < nums.size(); i++) {
            now = max(nums[i], now + nums[i]);
            ans = max(ans, now);
        }
        return ans;
    }
};