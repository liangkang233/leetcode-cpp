/*
 * @lc app=leetcode.cn id=1249 lang=cpp
 *
 * [1249] 移除无效的括号
 */

#include <string>
#include <iostream>
#include <stack>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i =0; i < s.size() ; ++i){
            if(s[i] == '(' || s[i] == ')'){
                if(s[i] == '(') 
                    st.push(i);
                else if(st.empty()) {
                    s.erase(i,1);
                    --i; // 删除多余的 ) 下标会变
                }
                else
                    st.pop();
            }
        }
        while(!st.empty()){
            int i = st.top(); // 从后往前删 这样栈内下标不会变
            s.erase(i,1);
            st.pop();
        }
        return s;
    }
};
// @lc code=end
// "))((dfasdfjkawiueyuifha(()))))))(((lkerjgkua(()fjhsjfhjsfkj))))"\n
// "))((dffshdfh(dsjhfjhsjfhjsf"\n
// "))(("\n

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; // 记录括号是否有效的栈
        unordered_set<int> myset;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')') {
                if(!st.empty()) {
                    myset.insert(st.top());
                    myset.insert(i);
                    st.pop();
                }
            }
        }
        string ans; // 不想直接在字符串上修改 想了个馊主意 用set记录有效下标
        for (int i = 0; i < s.size(); i++) {
            if(s[i] >= 'a' || myset.find(i) != myset.end())
                ans.push_back(s[i]);
        }
        return ans;
    }
};