/*
 * @lc app=leetcode.cn id=1592 lang=cpp
 *
 * [1592] 重新排列单词间的空格
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// @lc code=start
class Solution {
public:
    string reorderSpaces(string text) {
        istringstream in(text);
        int len = 0, k = 0, m;
        string temp;
        vector<string> v;
        while (in >> temp) {
            v.push_back(temp);
            len += temp.size();
        }
        if(v.size() > 1) 
            k = (text.size() - len) / (v.size() - 1);
        m = text.size() - len - (v.size()-1) * k;
        temp = v[0];
        // cout << k << " " << m << endl;
        for (int i = 1; i < v.size(); i++) {
            temp += string(k, ' ') + v[i];
        }
        temp += string(m, ' ');
        return temp;
    }
};
// @lc code=end

// "  walks  udp package   into  bar a"\n