/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

// @lc code=start
// 单调递减 双端队列  记录递减元素的下标
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> myque;   // 维护一个 nums[j]单调递减 j为元素的 双端队列
        for (int i = 0; i < nums.size(); i++) {
            while(!myque.empty() && nums[i] > nums[myque.back()]) 
                myque.pop_back();
            myque.push_back(i);
            if(myque.front() <= i-k)    //头不存在需要弹出
                myque.pop_front();
            if(i >= k-1)
                ans.push_back(nums[myque.front()]);
        }
        return ans;
    }
};
// @lc code=end
// [1, -1]\n1\n


// 直接set做很慢
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> myset;
        for (int i = 0; i < nums.size(); i++) {
            myset.insert(nums[i]);
            if (myset.size() > k)
                myset.erase(myset.find(nums[i - k]));
            if (myset.size() == k)
                ans.push_back(*myset.rbegin());
        }
        return ans;
    }
};

// 对堆 优先队列 进行修改
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>> myque; //元素为 值 下标 以值为参考大根堆
        for (int i = 0; i < nums.size(); i++) {
            myque.push(make_pair(nums[i], i));
            // cout << myque.top().second << i - k << endl;
            while (myque.top().second <= i - k)
                myque.pop();
            if(myque.size() >= k)
                ans.push_back(myque.top().first);
        }
        return ans;
    }
};