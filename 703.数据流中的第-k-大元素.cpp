/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>
using namespace std;

// 题意不需要去重

// @lc code=start
class KthLargest {
private:
    int size;
    priority_queue<int, vector<int>, greater<int>> myheap;
public:
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (int i = 0; i < nums.size(); i++)
            add(nums[i]);
    }
    int add(int val) {
        if(myheap.size() < size) {
            myheap.push(val);
        }
        else if(val > myheap.top()) { // 大于堆内最小值 才进行更新堆操作
            myheap.push(val);
            myheap.pop();
        }
        return myheap.top();
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

// 慎用 make_heap   少搞些花里胡哨的   用这个得考虑 初始数组是空 make_heap 重复会很慢 的情况 简单题做复杂了属于是
class KthLargest {
private:
    int size;
    vector<int> myheap;
public:
    int add(int val) {
        if(myheap.size() < size) {
            myheap.push_back(val);
            push_heap(myheap.begin(), myheap.end(), greater<int>());
        }
        else if(val > myheap[0]) { // 大于堆内最小值 才进行更新堆操作
            pop_heap(myheap.begin(), myheap.end(), greater<int>());
            myheap.back() = val;
            push_heap(myheap.begin(), myheap.end(), greater<int>());
        }
        cout << val << ": ";
        for (auto &&ii : myheap) {
            cout << ii << " ";
        }cout << endl;
        return myheap[0];
    }
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (int i = 0; i < nums.size(); i++)
            add(nums[i]);
    }
};