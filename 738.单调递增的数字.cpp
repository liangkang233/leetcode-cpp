/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<char> nums;
        int ans = 0;
        bool flag = false;
        while (n) {
            nums.push_back(n%10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if(flag)
                nums[i] = 9;
            else if(nums[i] < nums[i-1]) { // 找到第一个减少的数字位 将其减一 后面全赋9
                nums[i] = 9;
                nums[i-1]--;
                int index = i - 1;
                // 临界值减少 例如 188421 会变为 187421 前缀可能不匹配 往前遍历校对
                while(index > 0 && nums[index-1] > nums[index]){
                    nums[index--] = 9;
                    nums[index]--;
                }
                flag = true;
            }
        }
        for (int i = 0; i < nums.size(); i++)
            ans = 10  * ans + nums[i];
        return ans;
    }
};
// @lc code=end
// 1284687\n
// 332\n
// 999998\n