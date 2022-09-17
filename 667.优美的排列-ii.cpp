/*
 * @lc app=leetcode.cn id=667 lang=cpp
 *
 * [667] 优美的排列 II
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        int maxn = n, minn = 1;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if(flag) 
                ans[i] = minn++;
            else    
                ans[i] = maxn--;
            if(k > 1) {
                flag = !flag;
                // string s = flag ? "1" : "0"; cout << s << endl;
                k--;
            }
        }
        return ans;
    }
};
// @lc code=end
// 4\n3\n
