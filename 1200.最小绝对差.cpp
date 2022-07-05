/*
 * @lc app=leetcode.cn id=1200 lang=cpp
 *
 * [1200] 最小绝对差
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int M = INT_MAX;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++) {
            if(arr[i] - arr[i-1] <= M) {
                if(arr[i] - arr[i-1] < M)
                    ans.clear();
                ans.push_back(vector<int>{arr[i-1], arr[i]});
                M = arr[i] - arr[i-1];
            }
        }
        return ans;
    }
};
// @lc code=end

//  [1,3,6,10,15]\n [3,8,-10,23,19,-4,-14,27]