/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// 所有 单词都是 异位词 则相似即为 字符串两个字符不同
// 通过遍历判断相似 得出 edage 进行并查集 分组 此处可以不用路径压缩
class Solution {
public:
    int find(vector<int>& fa, int i) {
        if(fa[i] != -1) {
            fa[i] = find(fa, fa[i]);
            return fa[i];
        } return i;
    }
    void merge(vector<int>& fa, vector<int>& dep, int x, int y) {
        int rx = find(fa, x), ry = find(fa, y);
        if(rx != ry) { // rx ry 相同形成环 放弃合并处理
            if(dep[rx] < dep[ry])
                swap(rx, ry);
            else if(dep[rx] == dep[ry])
                dep[rx]++;
            fa[ry] = rx;
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        vector<int> fa(strs.size(), -1), dep(strs.size(), 0);
        auto isok = [](const string& a, const string& b) {
            int temp = 0;
            for (int i = 0; i < a.size(); i++) {
                if(a[i] != b[i] && ++temp > 2)
                    return false;
            }
            return temp != 1; // temp == 0、2 相等字符串 也视作相似
        };
        for (int i = 0; i < strs.size()-1; i++) {
            for (int j = i+1; j < strs.size(); j++) {
                if(isok(strs[i], strs[j]))
                    merge(fa, dep, i, j);
            }
        }
        int ans = 0;
        for (int i = 0; i < strs.size(); i++) {
            if(fa[i] < 0) ans++;
        }
        return ans;
    }
};
// @lc code=end

