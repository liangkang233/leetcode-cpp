// https://www.nowcoder.com/practice/3911a20b3f8743058214ceaa099eeb45?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    int minMoney(vector<int>& arr, int aim) {
        vector<int> dp(aim+1, -1);
        dp[0] = 0;
        sort(arr.begin(), arr.end());
        for (int i = 1; i <= aim; i++) {
            for (int j = 0; j < arr.size(); j++){
                if(i < arr[j]) break;
                else if(dp[i-arr[j]] < 0) continue;
                if(dp[i] < 0)
                    dp[i] = dp[i-arr[j]] + 1;
                else
                    dp[i] = min(dp[i], dp[i-arr[j]] + 1);
            }
        }        
        return dp[aim];
    }
};