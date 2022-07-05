/*
 * @lc app=leetcode.cn id=1405 lang=cpp
 *
 * [1405] 最长快乐字符串
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 贪心 每次都使用最多的字符

// @lc code=start
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> arr{make_pair(a, 'a'), make_pair(b, 'b'), make_pair(c, 'c')};
        string ans;
        while (1) {
            sort(arr.begin(), arr.end(), [](const pair<int, char> & p1, const pair<int, char> & p2) {
                return p1.first > p2.first;
            });
            bool flag = true;
            for (int i = 0; i < 3 && arr[i].first > 0; i++) {
                if(ans.size() > 1 && ans.back() == ans[ans.size()-2] && ans.back() == arr[i].second)
                    continue;
                ans.push_back(arr[i].second);
                arr[i].first--;
                flag = false;
                break;
            }
            if(flag)
                break;
            cout << ans << endl;
        }
        return ans;
    }
};
// @lc code=end
// 2\n2\n1\n
// 12\n22\n21\n