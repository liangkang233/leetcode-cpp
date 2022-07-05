// https://www.nowcoder.com/practice/ce73540d47374dbe85b3125f57727e1e?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 用递归回溯做我觉得更好写

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return string字符串vector
     */
    void myfun(vector<pair<int, string>>& abc, vector<pair<int, string>>& temp, const string& s) {
        if((s.size() == 2 && s[0] == '0') || (s.size() == 3 && (s[0] == '0' || stoi(s) > 255))) return;
        for (int i = 0; i < abc.size(); i++) {
            if(abc[i].first < 4) {
                string t = abc[i].first > 0 ? abc[i].second + "." + s : s;
                temp.push_back(make_pair(abc[i].first+1, t));                
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<pair<int, string>> a, b, c = {make_pair(0, "")};
        if(s.size() < 4) return ans;
        for (int i = 0; i < s.size(); i++) {
            vector<pair<int, string>> temp;
            myfun(c, temp, s.substr(i, 1));
            if(i >= 1) myfun(b, temp, s.substr(i-1, 2));
            if(i >= 2) myfun(a, temp, s.substr(i-2, 3));
            a = b;
            b = c;
            c = temp;
        }
        for (int i = 0; i < c.size(); i++) {
            if(c[i].first == 4)
                ans.push_back(c[i].second);
        }
        return ans;
    }
};