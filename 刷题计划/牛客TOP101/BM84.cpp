// https://www.nowcoder.com/practice/c3120c1c1bc44ad986259c0cf0f0b80e?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if(!strs.empty()) {
            ans = strs[0];
            for (int i = 0; i < strs.size() && !ans.empty(); i++) {
                ans = ans.substr(0, min(strs[i].size(), ans.size()));
                for (int j = 0; j < ans.size(); j++) {
                    if(strs[i][j] != ans[j]) {
                        ans = ans.substr(0, j);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int rows = strs.size();
        int cols = strs[0].size();
        //开始扫描
        for(int i=0;i<cols;i++){
            char firstChar = strs[0][i];
            for(int j=1; j<rows; j++){
                if(strs[j].length()==i || strs[j][i] != firstChar){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};
