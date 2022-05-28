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

// 二刷
// 使用 make_heap 来做
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mymap; // key 为元素 value 为对应出现次数
        vector<int> ans;
        auto mycmp = [&mymap](const int &a, const int &b)->bool {return mymap[a] > mymap[b];};
        for (int i = 0; i < nums.size(); i++)
            mymap[nums[i]]++;
        for (auto & pi : mymap) { // 创堆
            if(ans.size() < k ) {
                ans.push_back(pi.first);
                if(ans.size() == k)
                    make_heap(ans.begin(), ans.end(), mycmp); // 小根堆
            }
            else if (mycmp(pi.first, ans[0])) { //当前遍历值出现频率大于最小值 才对堆更新                 
                pop_heap(ans.begin(), ans.end(), mycmp);
                // ans.pop_back();
                // ans.push_back(pi.first);
                ans.back() = pi.first;
                push_heap(ans.begin(), ans.end(), mycmp);
            }
        }
        return ans;
    }
};
