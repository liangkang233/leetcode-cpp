/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短补全词
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int Min = -1;
        int ms[26] = {0};
        for (int i = 0; i < licensePlate.size(); i++) {
            if(licensePlate[i] <= 'z' && licensePlate[i] >= 'a')
                ms[licensePlate[i]-'a']++;
            else if(licensePlate[i] <= 'Z' && licensePlate[i] >= 'A')
                ms[licensePlate[i]-'A']++;
        }
        auto myfun = [](int* ms, const string& b) {
            int ms1[26] = {0};
            for (int i = 0; i < b.size(); i++) {
                ms1[b[i]-'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if(ms1[i] < ms[i]) return false;
            } return true;
        };
        
        for (int i = 0; i < words.size(); i++) {
            if(myfun(ms, words[i]) && (Min==-1 || words[i].size()<words[Min].size())) 
                Min = i;
        }
        return Min==-1 ? "" : words[Min];
    }
};
// @lc code=end

