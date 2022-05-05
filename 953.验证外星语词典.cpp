/*
 * @lc app=leetcode.cn id=953 lang=cpp
 *
 * [953] 验证外星语词典
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int ord[26] = {0};
        for (int i = 0; i < 26; i++)
            ord[order[i]-'a'] = i+1;
        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < words[i-1].size(); j++) { //只需要按照上一个字符的长度做对比
                int last = ord[words[i-1][j]-'a'];
                int now = j < words[i].size() ? ord[words[i][j]-'a'] : 0;
                // cout << last << " " << now << " ";
                if(now < last)
                    return false;
                else if(now > last)
                    break;
            }
            // cout << endl;
        }
        return true;
    }
};
// @lc code=end

