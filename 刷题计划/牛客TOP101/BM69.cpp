// https://www.nowcoder.com/practice/046a55e6cd274cffb88fc32dba695668?tpId=295&tqId=1024831&ru=%2Fpractice%2F3911a20b3f8743058214ceaa099eeb45&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    // 题目的意思是部分翻译 例如 1010 只能翻译为 10 + 10 一种
    // 而 100 这个数字的00, 或者 012 这类前导0都是非法的 ，只能翻译为 0 种
    int solve(string nums) {
        if(nums.empty() || nums[0] == '0') return 0;
        int last = 0, now = 1;
        for (int i = 1; i <= nums.size(); i++) { // i 代表nums长度
            int temp = now;
            if(nums[i-1] == '0') // 不为0 now 才能继承前一位的值
                now = 0;
            if(i > 1 && (nums[i-2] == '1' || (nums[i-2] == '2' && nums[i-1] <= '6')))
                now += last;
            last = temp;
        }
        return now;
    }
};

class Solution {
public:
    int solve(string nums) {
        vector<int> dp(nums.size()+1);
        if(nums.empty() || nums == "0") return 0;
        dp[0] = 1;
        for(int i = 1; i <= nums.size(); i++) {
            dp[i] = nums[i-1] == '0' ? 0 : dp[i-1];
            if((i > 1) && ((nums[i-2] == '1') 
                  || (nums[i-2] == '2' && nums[i-1] <= '6'))) {
                  dp[i] += dp[i-2];
            }
        }
        return dp[nums.size()];
    }
};