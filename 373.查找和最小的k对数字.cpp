/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>
using namespace std;

// @lc code=start
// 由于是两个递增数列，所以可以如此添加有效元素组。
// 维护堆提取top k组合  pair默认比较第一个元素 无需重载
// 无序set去重 但是pair没有hash函数 无法直接用unordered_set 需要传入一个自实现hash
// 否则只能用默认的set(带排序)去重了 如此还不如一开始就用set做排序不用堆了 例如下面法2
struct SimpleHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return hash<int>{}(p.first) ^ hash<int>{}(p.second);
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

// [1,2,4,5,6,7,8,1234,2134234,12313123]\n[1,2,3,4,5,6,234,893,1234,12345]\n20


// 这是用set的排序做的(底层平衡树，所有元素都是有序的，而堆只维护堆头，所以此题优先队列更快）
class Solution1 {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        set<tuple<int, int, int>> s;
        s.insert({nums1[0] + nums2[0], 0, 0});
        vector<vector<int>> res;
        while (res.size() < k && s.size()) {
            auto x = *s.begin();
            int a = get<0> (x), b = get<1> (x), c = get<2> (x);
            s.erase(s.begin());
            res.push_back({nums1[b], nums2[c]});
            if (b + 1 < n) {
                s.insert({nums1[b + 1] + nums2[c], b + 1, c});
            }
            if (c + 1 < m) {
                s.insert({nums1[b] + nums2[c + 1], b, c + 1});
            }
        }
        return res;
    }
};