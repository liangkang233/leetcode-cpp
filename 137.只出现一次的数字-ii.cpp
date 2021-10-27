/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/* 
pair 很容易转为数组或tuple类型
然后数组转 下面右值引用的例子
下面的auto用法做例子

int a[2] = {1,2};
auto [x,y] = a; // 创建e[2]，将a复制到e中，然后x指向e[0]， y指向e[1]
auto& [xr, yr] = a; // xr 引用指向 a[0], yr 引用指向 a[1] */


// @lc code=start
// 常规做法 哈希map 时间复杂度O(n) 空间复杂度O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans;
        unordered_map<int, int> ansmap;
        for(int num : nums) {
            ansmap[num]++;
        }
        for ( auto [num, count] : ansmap) {
            if (count == 1) {
                ans = num;
                break;
            }
        }
        return ans;
    }
};
// @lc code=end

//  累加确定二进制位 时间复杂度O(nlogC) 空间复杂度O(1)
class Solution0 {
public:
    int singleNumber(vector<int>& nums) {
        int ans;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (int num: nums) {
                total += ((num >> i) & 1);
            }
            if (total % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

// 超级秀的空间复杂度1的做法 数字电路 时间复杂度O(n) 空间复杂度O(1)
// https://leetcode-cn.com/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetc-23t6/
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for(int num : nums) {
            b = ~a & (b ^ num);
            a = ~b & (a ^ num);
        }
        return b;
    }
};

