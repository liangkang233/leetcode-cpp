/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */

#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int ans = INT_MAX, Q = 24*60;
        set<int> myset;
        auto totime = [](const string& timePoint) {
            int time = stoi(timePoint.substr(0, 2)) * 60;
            time += stoi(timePoint.substr(3, 2));
            return time;
        };
        for (int i = 0; i < timePoints.size(); i++) {
            int time = totime(timePoints[i]);
            if(myset.find(time) != myset.end())
                return 0;
            myset.insert(time);
        }
        // 由于哈希 最大为24*60个 比较差值 时间复杂度 n^2 不会超时
        vector<int> vt;
        vt.reserve(myset.size());
        for (auto &&i : myset)
            vt.emplace_back(i);
        for (int i = 0; i < vt.size(); i++) {
            for (int j = i+1; j < vt.size(); j++) {
                ans = min(ans, min(vt[j]-vt[i], vt[i]-vt[j]+Q));
                // cout << ans << endl;
            }
        }
        // return ans == INT_MAX ? -1 : ans;
        return ans;
    }
};
// @lc code=end
// ["00:00","23:59","00:00"]

