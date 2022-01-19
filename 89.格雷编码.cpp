/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

// @lc code=start
// 背公式吧 格雷码
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1 << n);
        for (int i = 0; i < ret.size(); i++) {
            ret[i] = (i >> 1) ^ i;
        }
        return ret;
    }
};
// @lc code=end

// 回转后 首位加1
class Solution1 {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.reserve(1 << n);
        ans.push_back(0);
        for (int i = 1; i <= n; i++) {
            int m = ans.size();
            for (int j = m - 1; j >= 0; j--) {
                ans.push_back(ans[j] | (1 << (i - 1)));
            }
        }
        return ans;
    }
};
// 上面反转的回溯做法
class Solution11 {
public:
    vector<int> ans{0};
    void mydfs(int n) {
        if(n<=0)
            return;
        mydfs(n-1);
        int temp = 1 << n-1;
        for (int i = ans.size()-1; i >= 0; i--)
            ans.push_back(temp | ans[i]);
    }
    vector<int> grayCode(int n) {
        mydfs(n);
        return ans;
    }
};


// 丢人玩意 5.2% 5.01%
class Solution2 {
public:
    vector<int> ans{0};
    unordered_set<int> myset{0};
    bool mydfs(int k, int n) {
        if(k >= pow(2, n) - 1) { //填入完毕，判断是否满足第1位与最后1位仅仅1位不同
            int temp = 0;
            for (int i = 0; i < n; i++) {
                if(ans[0]^ans[k]>>i & 1)
                    temp++;
            }
            if(temp == 1)
                return true;
            return false;
        }
        for (int i = 0; i < n; i++) { //遍历不重复的修改单个元素内的某1位
            int temp = ans[k]>>i & 1 ? ans[k]-(1<<i): ans[k]+(1<<i);  // 修改从右至左数第i位
            // cout << temp << " " << ans[k] << endl;
            if(myset.find(temp)!=myset.end())
                continue;
            // cout << temp << endl;
            ans.push_back(temp);
            myset.insert(temp);
            if (mydfs(k+1, n))
                return true;
            ans.pop_back(); // 递归失败回溯
            myset.erase(temp);
        }
        return false;
    }
    vector<int> grayCode(int n) {
        mydfs(0, n); // 计数值 单个元素位数、元素个数 pow(2, n-1)
        return ans;
    }
};