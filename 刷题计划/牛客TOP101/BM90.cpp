// https://www.nowcoder.com/practice/c466d480d20c4c7c9d322d12ca7955ac?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param S string字符串 
     * @param T string字符串 
     * @return string字符串
     */
    bool isok(vector<int>& myset) {
        for (int i = 0; i < 128; i++) {
            if(myset[i] > 0) 
                return false;
        }
        return true;
    }
    string minWindow(string S, string T) {
        vector<int> myset(128, 0);
        int index = -1, count = INT_MAX;
        for (int i = 0; i < T.size(); i++) myset[T[i]]++;
        for (int r = 0, l = 0; r < S.size(); r++) {
            myset[S[r]]--;
            while (isok(myset)) {
                // cout << l << " " << r << endl;
                if(r-l+1 < count) {
                    index = l;
                    count = r-l+1;
                }
                myset[S[l++]]++;
            }
        }
        // cout << index << " " << count << endl;
        return index < 0 ? "" : S.substr(index, count);
    }
};
