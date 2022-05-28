/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    int n, k;
public:
    void mydfs(vector<int>& temp, int now) {
        // for (auto &&i : temp) {
        //     cout << i << " ";
        // }cout << endl;
        
        if(temp.size() >= k) {
            ans.push_back(temp);
        } else if(k-temp.size() > n-now) { // 剪枝 不可能凑出k个
            ;
        } else {
            for (int i = now+1; i <= n; i++) {
                temp.push_back(i);
                mydfs(temp, i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        this->n = n, this->k = k;
        mydfs(temp, 0);
        return ans;
    }
};
// @lc code=end

