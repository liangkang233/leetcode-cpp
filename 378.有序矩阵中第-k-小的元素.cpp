/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */
// 给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
// 请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// @lc code=start
// 二分法
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), min=matrix[0][0], max=matrix[n-1][n-1];
        while (min < max){
            int num = 0, temp = n-1, mid = (min + max)/2;
            for (int i = 0; i < n; i++) {
                for (int j = temp; j >= 0; j--) {
                    temp = j;
                    if (matrix[i][j] <= mid) {
                        num+=j+1;
                        break;
                    }
                }
            }
            if (num >= k)
                max = mid;
            else
                min = mid+1;
        }
        return min;
    }
};
// @lc code=end

// 直接使用优先队列（小根堆）
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        struct point {
            int val, x, y;
            point(int val, int x, int y) : val(val), x(x), y(y) {}
            bool operator> (const point& a) const { return this->val > a.val; }
        };
        // 小根堆 最小值在前
        priority_queue<point, vector<point>, greater<point>> que;
        // 第一个参数是存储对象的类型，第二个参数是存储元素的底层容器，第三个参数是函数对象
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            que.emplace(matrix[i][0], i, 0);
        }
        for (int i = 0; i < k - 1; i++) {
            point now = que.top();
            que.pop();
            if (now.y != n - 1) {
                que.emplace(matrix[now.x][now.y + 1], now.x, now.y + 1);
            }
        }
        return que.top().val;
    }
};

// 使用归并排序 的思想 参考题目23   这样和小根堆都是没用到这个二维是已经排序过的性质
/* class Solution {
public:
    vector<int>& kmerge(vector<vector<int>>& matrix, int l, int r) {
        if (l >= r)
            return matrix[l];
        return append(kmerge(matrix, l, (l+r)/2),kmerge(matrix,(l+r)/2+1,r));
    }
    vector<int>& append(vector<int>& L, vector<int>& R) {
        vector<int> myarry;
        vector<int>::iterator ll=L.begin(), rr=R.begin();
        while (ll!=L.end() && rr!=R.end()) {
            if (*ll <= *rr)
                myarry.push_back(*ll++);
            else 
                myarry.push_back(*rr++);
        }
        while (ll!=L.end())
            myarry.push_back(*ll++);
        while (rr!=L.end())
            myarry.push_back(*rr++);
        return myarry;
        // 这个写法有问题 不像题目23那样是链表，这里得用队空间容器 
        // 总之很浪费空间 且时间复杂度也高不如用 堆（优先队列）
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        kmerge(matrix, 0, n-1);
    }
}; */


