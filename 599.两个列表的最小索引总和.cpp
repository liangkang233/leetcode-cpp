/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mymap;
        vector<string> ans;
        int minindex = INT_MAX;
        for (int i = 0; i < list1.size(); i++)
            mymap.insert(make_pair(list1[i], i));
        for (int i = 0; i < list2.size(); i++) {
            if(mymap.find(list2[i]) != mymap.end()) {
                int temp = i + mymap.find(list2[i])->second;
                if(temp < minindex) {
                    ans.clear();
                    ans.push_back(list2[i]);
                    minindex = temp;
                }
                else if(temp == minindex)
                    ans.push_back(list2[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

// ["Shogun","Tapioca Express","Burger King","KFC"]\n["Tapioca Express","Shogun","BurgerKing"]\n
