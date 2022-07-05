// https://www.nowcoder.com/practice/e016ad9b7f0b45048c58a9f27ba618bf?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        if(a.empty()) return 0;
        sort(a.begin(), a.end(), greater<int>());
        return a[K-1];
    }
};

// 堆 或者 快排都行

// 手写快排 递增排列
class Solution {
public:
    void mysort(vector<int>& a, int L, int R) {
        if(L >= R) return;
        swap(a[L], a[rand() % (R-L+1) + L]); // 加入随机值
        int k = a[L], l = L, r = R;
        while (l < r) {
            while (l < r && a[r] <= k) {
                r--;
            } a[l] = a[r];
            while (l < r && a[l] >= k) {
                l++;
            } a[r] = a[l];
        }
        a[l] = k;
        mysort(a, L, l-1);
        mysort(a, l+1, R);
    }
    int findKth(vector<int> a, int n, int K) {
        if(a.empty()) return 0;
        mysort(a, 0, a.size()-1);
        return a[K-1];
    }
};

