// https://www.nowcoder.com/practice/5164f38b67f846fb8699e9352695cd2f?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定数组的最长严格上升子序列的长度。
     * @param arr int整型vector 给定的数组
     * @return int整型
     */
    int LIS(vector<int>& arr) {
        vector<int> dp(arr.size(), 1);
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) { // dp[i] 表示以i结尾的最长序列
            for (int j = i-1; j >= 0 && j+1 >= dp[i]; j--) {
                if(arr[i] > arr[j])
                    dp[i] = max(dp[j]+1, dp[i]);
            }
            ans = max(ans, dp[i]);
            // cout << i << " : " << dp[i] << endl;
        }
        return ans;
    }
};