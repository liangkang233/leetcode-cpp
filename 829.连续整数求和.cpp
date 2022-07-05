/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
 */

// @lc code=start
// 数量级到达 10^9 滑动窗口也会超时
// 根据 等差数列求和 i 到 i+k-1 的数字和 n = (i + i+k-1) / 2 * k = i*k + k*(k-1) / 2;
// 即为 n - k*(k-1)/2 = k*i  => (n-sum) % k == 0   (i>=1 k>=1)
// n需要为等差数列 0到k-1 和的k倍数
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0, sum = 0;
        for (int i = 1; sum < n; i++) {
            if((n-sum) % i == 0)
                ans++;
            sum+=i;
        } return ans;
    }
};
// @lc code=end

// 类似解法
// 将 n - k*(k-1)/2 = k*i  => n - k*(k+1)/2 = k*i - k*k
// => (n-sum) % k == 0         n需要为等差数列 1到k 和的k倍数 
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        int i = 1;
        while(n > 0){
            n -= i;
            if(n % i == 0)
                count++;
            i++;
        }
        return count;   
    }
};