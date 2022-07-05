/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> table;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            // unordered_map<int, vector<int>>::iterator it = table.find(nums[i]);
            auto it = table.find(nums[i]);
            if (it == table.end())
                table.insert({ nums[i], vector<int>{i} });
            else
                it->second.push_back(i);
        }
        for (auto i = table.begin(); i != table.end(); i++) {
            if (i->second.size() == 0)
                continue;
            int cha = target - i->first;
            if (cha == i->first) {
                while (i->second.size() > 1) {
                    ans.push_back(*i->second.begin());
                    ans.push_back(*(i->second.begin() + 1));
                    i->second.pop_back();
                    i->second.pop_back();
                }
                i->second.clear();
                continue;
            }
            auto j = table.find(cha);
            if (j == table.end())
                continue;
            while (!j->second.empty() && !i->second.empty() ) {
                ans.push_back(*i->second.rbegin());
                ans.push_back(*j->second.rbegin());
                j->second.pop_back();
                i->second.pop_back();
            }
            if (!j->second.empty() )
                j->second.clear();
            if (!i->second.empty() )
                i->second.clear();
        }
        return ans;
    }
};
// @lc code=end


// 把题目想复杂了，一开始导入map的时候就可以判断了
// 而且每个输入的问题只有一组解

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};


// 二刷
// 这道题就是哈希的边遍历 边查询 一开始用排序双指针没去重也太菜了
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.find(target - nums[i]) != mp.end())
                return vector<int>{mp[target-nums[i]], i};
            mp[nums[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};