/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans, arr1(arr.size()+1);
        copy(arr.begin(), arr.end(), arr1.begin()+1); // copy 和 insert 被放入的地方是相反的
        arr1[0] = INT_MIN;
        vector<int>::iterator l , r;
        r = upper_bound(arr1.begin(), arr1.end(), x);
        l = r-1;
        while (k--) {
            if(l == arr1.begin()) {
                r++;
            } else if(r == arr1.end()) {
                l--;
            } else {
                if(abs(x-*l) > abs(x-*r)) {
                    r++;
                } else {
                    l--;
                }
            }
        }
        ans.insert(ans.begin(), l+1, r);
        return ans;
    }
};
// @lc code=end