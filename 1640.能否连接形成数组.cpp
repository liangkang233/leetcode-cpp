/*
 * @lc app=leetcode.cn id=1640 lang=cpp
 *
 * [1640] 能否连接形成数组
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


// 没想到用哈希来做直接遍历判断 暴力dfs写的很麻烦
// @lc code=start
bool mydfs(vector<int>& arr, vector<vector<int>>& pieces, int index, unordered_set<int>& us) {
    if(index == arr.size()) return true;
    auto isvaild = [&](int p) {
        for (int i = index, k = 0; k < pieces[p].size(); i++, k++) {
            if(arr[i] != pieces[p][k]) 
                return false;    
        }
        return true;
    };
    for(int p = 0; p < pieces.size(); p++) {
        if(us.find(p) != us.end()) continue;
        if(!isvaild(p)) continue;
        us.insert(p);
        if(mydfs(arr, pieces, index+pieces[p].size(), us)) return true;
        us.erase(p);
    }
    return false;
}

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        // int size = 0; // 题中说明一定相等
        // for(auto & ii : pieces) size += ii.size();
        // if(size != arr.size()) return false;
        unordered_set<int> us;
        return mydfs(arr, pieces, 0, us);
    }
};
// @lc code=end
[37,69,3,74,46]\n[[37,69,3,74,46]]

// 题目中说明 各个数字不相同 确保没有重复首元素，所以可以直接用首元素做判断
class Solution {
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
        unordered_map<int, int> index;
        for (int i = 0; i < pieces.size(); i++) {
            index[pieces[i][0]] = i;
        }
        for (int i = 0; i < arr.size();) {
            auto it = index.find(arr[i]);
            if (it == index.end()) {
                return false;
            }
            for (int x : pieces[it->second]) {
                if (arr[i++] != x) {
                    return false;
                }
            }
        }
        return true;
    }
};
