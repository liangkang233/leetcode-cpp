/*
 * @lc app=leetcode.cn id=899 lang=cpp
 *
 * [899] 有序队列
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    string orderlyQueue(string s, int k) {
        string ans(s);
        if(k > 1) { // 只要k大于1 一定能贪心出最小字典序 举例 当k大于2就相当于能够修改两端的顺序进行排序
            sort(ans.begin(), ans.end());
        } else {
            char mchar = s[0];
            for(int i = 0; i < s.size(); i++) mchar = min(mchar, s[i]);
            for(int i = 1; i < s.size(); i++) {
                if(s[i] == mchar)
                    ans = min(ans, s.substr(i) +  s.substr(0, i));
            }
        }
        return ans;
    }
};
// @lc code=end
// "caaba"\n3\n
// "dcabe"\n2\n"gfhjiasgjkljoeuroigualskjdkfhajksdhfjkdcabe"\n3\n