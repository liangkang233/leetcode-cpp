/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 字典序排列 递归做法(只可以用于不同元素) 
// 但此题求所有子序列 子序列下标不同，元素相同 也是不同子序列
// 所以不考虑重复元素可以用递归 例如 [1,1] 有两个子序列 为[1,1] [1,1]
// 注意直接递归swap不做处理非字典序
// 不加个阶乘判断 会超时

// @lc code=start
class Solution {
public:
    int jc[10] = {1};
    // 每确定一位数字就可知其k的范围为 [1 + i*interval, (i+1)*interval]
    void mydfs(string& ans, vector<char>& myset, int k) {
        for (int i = 0; i < myset.size(); i++) {
            int interval = jc[myset.size()-1];
            if(k <= (i+1) * interval) {
                ans.push_back(myset[i]);
                myset.erase(myset.begin()+i);
                mydfs(ans, myset, k - i*interval);
                break;
            }
        }
    }
    string getPermutation(int n, int k) {
        string ans;
        vector<char> myset(n, '0');
        for (int i = 1; i <= n; i++) { //0-n阶乘值 (n为 1-9) 即 X! = jc[x]
            jc[i] = jc[i-1] * i;
            myset[i-1] = '0' + i;
        }
        mydfs(ans, myset, k);
        return ans;
    }
};
// @lc code=end
// 4\n3
// 4\n4
// 9\n10
// 9\n100
// 9\n362880
// 9\n1

// 深度太大会超时
class Solution1 {
public:
    int count = 0;
    bool mydfs(string& ans, vector<bool>& myset) {
        if(ans.size() >= myset.size()) {
            if(--count <= 0)
                return true;
        }
        for (int i = 0; i < myset.size(); i++) {
            if(myset[i])
                continue;
            myset[i] = true;
            ans.push_back(i + '1');
            if (mydfs(ans, myset))
                return true;
            // 递归失败 回溯
            myset[i] = false;
            ans.pop_back();
        }
        return false;
    }
    string getPermutation(int n, int k) {
        string ans;
        count = k;
        vector<bool> myset(n, false); //true 为该 (下标+1) 被使用
        mydfs(ans, myset);
        return ans;
    }
};

// 注意直接递归swap不做处理非字典序 以下为错误
class Solution2 {
public:
    int count = 0;
    bool mydfs(string& ans, int start) {
        if(start >= ans.size()) {
            cout << ans << " " << count << endl;
            if(--count <= 0)
                return true;
        }
        for (int i = start; i < ans.size(); i++) {
            swap(ans[start], ans[i]);
            if (mydfs(ans, start+1))
                return true;
            swap(ans[i], ans[start]);
        }
        return false;
    }
    string getPermutation(int n, int k) {
        string ans;
        count = k;
        for (int i = 0; i < n; i++)
            ans.push_back('1' + i);
        mydfs(ans, 0);
        return ans;
    }
};