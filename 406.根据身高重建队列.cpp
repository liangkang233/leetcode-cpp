/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
// 妙啊！
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 按照 身高递减 身高相同则次序小的在前 规律
        auto mycmp = [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        };
        sort(people.begin(), people.end(), mycmp);
        // for (int i = 0; i < people.size(); i++)
        //     cout << people[i][0] << " " << people[i][1] << endl;
        // 且按照 mycmp 的排列 遍历的当前元素 身高越来越小
        // 插入任何一个人到i位置时 前i-1个人  和 i+1 到n的身高 结果都不受影响
        // 当身高相同时 由于先插入 次序小的 再插入次序大的结果也不会身高相同的元素
        vector<vector<int>> ans{people[0]};
        for (int i = 1; i < people.size(); i++) {
            ans.insert(ans.begin() + people[i][1], people[i]);
        }
        return ans;
    }
};
// @lc code=end


// 身高递增排列
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });
        int n = people.size();
        vector<vector<int>> ans(n);
        for (const vector<int>& person: people) {
            int spaces = person[1] + 1;
            for (int i = 0; i < n; ++i) {
                if (ans[i].empty()) {
                    --spaces;
                    if (!spaces) {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};


// 原思路 但是没做出 看看官解
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        }); // 身高递增排列 若身高相等则 按照次序递减少 排列
        // 则遍历时 ans 节点为空的表示这些节点大于等于 自己  所以身高相等的节点, 次序要递减
        int n = people.size();
        vector<vector<int>> ans(n); // 先分配n个空间
        for (const vector<int>& person: people) {
            int spaces = person[1] + 1; // 该节点占用空间为 大小加上自己
            for (int i = 0; i < n; ++i) {
                if (ans[i].empty()) {
                    --spaces;
                    if (!spaces) {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
