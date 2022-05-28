/*
 * @lc app=leetcode.cn id=873 lang=cpp
 *
 * [873] 最长的斐波那契子序列的长度
 */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution { // 正着 遍历最后两个元素 效果更好
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0, n = arr.size(); // 斐波那契长度 最短为3
        unordered_map<int, int> in;  // 值对应下标
        for (int i = 0; i < n; i++)
            in.insert(make_pair(arr[i], i));
        vector<vector<int>> dp(n, vector<int>(n, 0)); // dp[i][j] 表示以 ij为末尾两元素的 最大斐波那契长度
        for (int j = 2; j < n; j++) {
            for (int i = j-1; i >= 1; i--) {
                int k = arr[j]-arr[i];
                if(k >= arr[i]) // 由于arr严格递增，向前的遍历的元素必定不存在
                    break;
                if(in.find(k) == in.end())
                    continue;
                int kk = in[k];
                dp[i][j] = max(dp[kk][i], 2) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
// @lc code=end
// [1,3,7,11,12,14,18]\n
// [1,2,3,5,7,8,11,12,13,14,18]\n

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0, n = arr.size(); // 斐波那契长度 最短为3
        unordered_map<int, int> in;  // 值对应下标
        for (int i = 0; i < n; i++)
            in.insert(make_pair(arr[i], i));
        vector<vector<int>> dp(n, vector<int>(n, 0)); // dp[i][j] 表示以 ij为初始两元素的 最大斐波那契长度
        for (int j = n-2; j >=0; j--) {
            for (int i = 0; i < j; i++) {
                int k = arr[j]+arr[i];
                // cout << k << " " << arr[i] << " " << arr[j] << endl;
                if (k > arr.back()) // 由于arr严格递增，向后的遍历的元素会更大
                    break;
                if (in.find(k) == in.end())
                    continue;
                int kk = in[k];
                dp[i][j] = max(dp[j][kk], 2) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int N = A.size();
        unordered_map<int, int> index;
        for (int i = 0; i < N; ++i)
            index[A[i]] = i;

        unordered_map<int, int> longest;
        int ans = 0;
        for (int k = 0; k < N; ++k)  // j k 为序列的最后两个元素 其值 dp[j][k] 对应 longest[j * N + k]  为最大长度
            for (int j = 0; j < k; ++j) {
                if (A[k] - A[j] < A[j] && index.count(A[k] - A[j])) {
                    int i = index[A[k] - A[j]];
                    longest[j * N + k] = longest[i * N + j] + 1;
                    ans = max(ans, longest[j * N + k] + 2);
                }
            }

        return ans >= 3 ? ans : 0;
    }
};