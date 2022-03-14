/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> temp_path;    // 记录遍历过程中的临时路径
        string ans = "", temp = "";
        int flag = 0;
        path.push_back('/');    //手动补齐一个
        for (int i = 0; i < path.size(); i++) {
            if(path[i] == '/') {
                if(flag>2) //flag有值代表该区间只有. 且temp为空，确定flag值即可
                    temp = string(flag, '.');
                else if (flag == 2) {
                    if(!temp_path.empty())
                        temp_path.pop();
                }
                if(!temp.empty()) {
                    reverse(temp.begin(), temp.end()); // 提前反转 为最后反push出来做准备
                    temp_path.push(temp);
                }
                temp = "";
                flag = 0;
            }
            else {
                if(path[i] == '.' && temp.empty())
                    flag++;
                else{
                    temp += string(flag, '.');
                    flag = 0;
                    temp.push_back(path[i]);
                }
            }
        }
        while (!temp_path.empty()) {
            ans += temp_path.top() + "/";
            temp_path.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "/" : ans;
    }
};
// @lc code=end

// "/../"\n
// "/./ds"\n
// "/../ds"\n
// "/.../ds"\n
// "/...io/ds"\n
// "/dfhjf/df/.../"\n
// "/d./"\n

// "/a/./b/../c/"\n
// "/a//b////c/d//././/.."\n

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> st;
        int n = path.size(), i = 0;
        while(i < n){
            if(i < n && path[i] == '/') i++;
            else{
                string temp;
                while(i < n && path[i] != '/') temp += path[i++];
                if(temp == ".." && !st.empty()) st.pop_back();
                else if(temp != ".." && temp != ".") st.push_back(temp); 
            }
        }
        string res = "/";
        while(!st.empty()){
            res += st.front() + "/";
            st.pop_front();
        }
        if(res.size() > 1) res.pop_back();
        return res;
    }
};