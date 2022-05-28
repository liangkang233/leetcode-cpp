/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

#include <vector>
#include <unordered_set>
#include <iostream>
#include <queue>
using namespace std;

// 由于是两个递增数列，所以可以如此添加有效元素组。
// 维护堆提取top k组合  pair默认比较第一个元素 无需重载
// 无序set去重 但是pair没有hash函数 无法直接用unordered_set 需要传入一个自实现hash
// 否则只能用默认的set(带排序)去重了 如此还不如一开始就用set做排序不用堆了 例如下面法2
// @lc code=start
struct SimpleHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};

class Solution {
public:
    typedef pair<int, pair<int, int>> mypair; //数组对的和 下标pair
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        unordered_set<pair<int, int>, SimpleHash> myset; //数列对 需要去重
        // set<pair<int, int>> myset; //数列对 需要去重
        priority_queue<mypair, vector<mypair>, greater<mypair>> myheap;
        int size1 = min(k, int(nums1.size())), size2 = min(k, int(nums2.size()));
        myheap.push( make_pair(nums1[0] + nums2[0], make_pair(0, 0)) );
        // cout << size1 << " " << size2 << endl;
        while (!myheap.empty() && k-- > 0) {
            int L = myheap.top().second.first, R = myheap.top().second.second;
            // cout << L << " " << R << endl;
            myheap.pop();
            ans.push_back(vector<int>{nums1[L], nums2[R]});
            if(L+1<size1 && myset.find(make_pair(L+1, R))==myset.end()) {
                myheap.push( make_pair(nums1[L+1] + nums2[R], make_pair(L+1, R)) );
                myset.insert(make_pair(L+1, R));
            }
            if(R+1<size2 && myset.find(make_pair(L, R+1))==myset.end()) {
                myheap.push( make_pair(nums1[L] + nums2[R+1], make_pair(L, R+1)) );
                myset.insert(make_pair(L, R+1));
            }
        }
        return ans;
    }
};
// @lc code=end

// 二刷  直接用队列做  不需要去重
typedef pair<int, int> pi;
typedef pair<int, pi> PI;
struct mycmp {
    bool operator() (const PI& a, const PI& b) {
        return a.first < b.first;
    }
};
class Solution {
public:
    // nums1 nums2 升序
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<PI, vector<PI>, mycmp> myque; // 大根堆
        vector<vector<int>> ans;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                int val = nums1[i] + nums2[j];
                PI p{val, pi{nums1[i], nums2[j]}};
                // cout << val << " ";
                if(myque.size() < k)
                    myque.push(p);
                else if(val < myque.top().first) { // 小于 当前堆最大值进行更新 否则break此次遍历
                    myque.push(p);
                    myque.pop();
                } else {
                    break;
                }
            }
            // cout << endl;
        }
        while(!myque.empty()) {
            pi p = myque.top().second;
            ans.push_back(vector<int>{p.first, p.second});
            myque.pop();
        }
        return ans;
    }
};