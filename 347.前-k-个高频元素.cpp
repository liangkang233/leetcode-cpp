/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// @lc code=start
class mycmp {
public:
    bool operator() (const pair<int, int> a, const pair<int, int> b) {
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        vector<int> ans(k);
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> myque; // 按照second次序排序的小根堆
        for (int i = 0; i < nums.size(); i++)
            mymap[nums[i]]++;
        for (auto & pi : mymap) { // 创堆
            if(myque.size() < k )
                myque.push(pi);
            else if (pi.second > myque.top().second) {
                myque.pop();
                myque.push(pi);
            }
        }
        for (int i = 0; i < k; i++) { // 整合数据
            ans[i] = myque.top().first;
            myque.pop();
        }
        return ans;
    }
};
// @lc code=end

// [1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,6,6,6,6,6,6,4,4,4,4,4,4,6,6,6,6,8,8,8,8,8,10]\n5
