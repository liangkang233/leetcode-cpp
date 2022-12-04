/* 面试题17.19.消失的两个数字

给定一个数组， 包含从1到N所有的整数，但其中缺了两个数字。
你能在O(N)时间内只用O(1) 的空间找到它们吗? 
以任意顺序返回这两个数字均可。
示例1:
    输入: [1]
    输出: [2,3]
    
示例2:
    输入: [2,3]
    输出: [1,4]
提示:

nums.length <= 30000 */

#include <iostream>
#include <vector>
using namespace std;

// 关键在于 抽屉排序 秒啊 https://blog.csdn.net/bianchengxiaosheng/article/details/102778510 时间复杂度O(n)
// for (int i = 0; i < data.size(); i++) {
//     while (i != data[i] - 1) {
//         swap(data[i], data[data[i]-1]);
//     }
// }
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        vector<int> ans;
        nums.push_back(-1);
        nums.push_back(-1);
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != -1 && i != nums[i]-1) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            // cout << nums[i] << " ";
            if(nums[i] == -1) ans.push_back(i+1);
        }
        // cout << endl;
        return ans;
    }
};  



// https://leetcode.cn/problems/missing-two-lcci/solution/xiao-shi-de-liang-ge-shu-zi-by-leetcode-zuwq3/
// 官解这个让我想到了 260.只出现一次的数字-iii.cpp 的做法
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int xorsum = 0;
        int n = nums.size() + 2;
        for (int num : nums) {
            xorsum ^= num;
        }
        for (int i = 1; i <= n; i++) {
            xorsum ^= i;
        }
        // 防止溢出
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
        int type1 = 0, type2 = 0;
        for (int num : nums) {
            if (num & lsb) {
                type1 ^= num;
            } else {
                type2 ^= num;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i & lsb) {
                type1 ^= i;
            } else {
                type2 ^= i;
            }
        }
        return {type1, type2};
    }
};
