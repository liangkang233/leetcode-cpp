/*
 * @lc app=leetcode.cn id=952 lang=cpp
 *
 * [952] 按公因数计算最大组件大小
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
// 并查集 对于是否相连不可直接用gcd会超时 优化为 构建nums中所有大于2的因数2-m的并查集 有环的连接跳过
// 即使nums中不包含其中的某些数 最后统计忽略这些数即可

// 为了得到数组nums中的每个数和哪些数属于同一个组件，需要得到数组nums中的最大值m,对于每个不
// 超过m的正整数num计算num和哪些数属于同一个组件。对于范围[2, √num内的每个正整数i, 如果i是num的因数，则num和i、num 都属于同一个组件。
// 可以使用并查集实现组件的计算。


int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
class unionfind {
private:
    vector<int> fa, rank;
public:
    unionfind(int size) {
        rank.resize(size);
        for (int i = 0; i < size; i++) fa.push_back(i);
    }
    int find(int n) {
        if(n != fa[n])
            fa[n] = find(fa[n]);
        return fa[n];
    }
    void merge(int a, int b) {
        int roota = find(a),rootb = find(b);
        if(roota == rootb) return;
        if(rank[roota] < rank[rootb]) swap(roota, rootb);
        fa[rootb] = roota;
        rank[roota]++;
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int ans = 0, M = 0;
        for (int i = 0; i < nums.size(); i++) M = max(nums[i], M);
        unionfind uf = unionfind(M+1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 2; j * j <= nums[i]; j++) { // 保证 nums[i]/j 大于等于j 即大于等于2   则nums[i]/j 也为 nums[i]的非0因数
                if(nums[i] % j == 0) {
                    uf.merge(nums[i], j);
                    uf.merge(nums[i], nums[i]/j);
                }
            }
        }
        vector<int> counts(M + 1);
        for (int num : nums) {
            int root = uf.find(num);
            counts[root]++;
            ans = max(ans, counts[root]);
        }
        return ans;
    }
};
// @lc code=end

