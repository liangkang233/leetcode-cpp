/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        ans[0] = 1;
        for(int i = 1; i < n; i++) {
            int temp = ans[i-1];
            if(temp * 10 <= n) {
                ans[i] = temp * 10;
            } else {
                while (temp + 1 > n || temp % 10 == 9) // 防止超出 和 9+1导致的进位
                    temp /= 10;
                ans[i] = temp + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

