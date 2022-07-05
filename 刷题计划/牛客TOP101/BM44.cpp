// https://www.nowcoder.com/practice/37548e94a270412c8b9fb85643c8ccc2?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        unordered_map<char, char> mp;
        mp[']'] = '[', mp[')'] = '(', mp['}'] = '{';
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if(mp.find(s[i]) == mp.end()) {
                st.push(s[i]);
            } else {
                if(st.empty() || st.top() != mp[s[i]])
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};