/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

// @lc code=start
bool fun(vector<int>& A, vector<int>& B) {
    return pow(A[0], 2) + pow(A[1], 2) < pow(B[0], 2) + pow(B[1], 2);
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // 暴力大概率超时,结果居然过了
        // Accepted
        // 85/85 cases passed (200 ms)
        // Your runtime beats 31.58 % of cpp submissions
        // Your memory usage beats 89.64 % of cpp submissions (48 MB)
        vector<vector<int>> ans;
        sort(points.begin(), points.end(), fun);
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
};
// @lc code=end


// 大意了 没想到堆排序
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(points[i][0] * points[i][0] + points[i][1] * points[i][1], i);
            // first 为距离 second 为下标   pair排序默认以第一个元素
        }
        int n = points.size();
        for (int i = k; i < n; ++i) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (dist < q.top().first) {
                q.pop();
                q.emplace(dist, i);
            }
        }
        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.push_back(points[q.top().second]);
            q.pop();
        }
        return ans;
    }
};


// 二刷 直接堆的效果甚至没有 sort好 
// 这里的数组应该优化为 pair 第一个元素为矢量距离  第二个元素为其 points下标
class mycmp {
public:
    bool operator() (const vector<int>& A, const vector<int>& B) {
        return pow(A[0], 2) + pow(A[1], 2) < pow(B[0], 2) + pow(B[1], 2);
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, mycmp> myque; // 大根堆 维护k个元素的大根堆
        auto myfun = [](const vector<int>& A, const vector<int>& B) {
            return pow(A[0], 2) + pow(A[1], 2) < pow(B[0], 2) + pow(B[1], 2);};
        for (int i = 0; i < points.size(); i++) {
            if(myque.size() < k)
                myque.push(points[i]);
            else if (myfun(points[i], myque.top())) {
                myque.push(points[i]);
                myque.pop();
            }
        }
        vector<vector<int>> ans(k);
        for (int i = 0; i < k; i++) {
            ans[i] = myque.top();
            myque.pop();
        }
        return ans;
    }
};