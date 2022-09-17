/*
 * @lc app=leetcode.cn id=636 lang=cpp
 *
 * [636] 函数的独占时间
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool fun(string& log, int& id, int& time) {
        string flag;
        for(int r = 0, l = 0, index = 0; r <= log.size(); r++) {
            if(r == log.size() || log[r] == ':' ) {
                string t = log.substr(l, r-l);
                l = r+1;
                if(index == 0) {
                    id = stoi(t);
                    index++;
                } else if (index == 1) {
                    flag = t;
                    index++;
                } else {
                    time = stoi(t);
                }
            }
        }
        return flag == "start";
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<pair<int, int>> st; // 记录上一个业务的 id号 启动时间
        for(int i = 0; i < logs.size(); i++) {
            int id, time;
            if(fun(logs[i], id, time)) { // start
                if(!st.empty()) // 进入函数递归 添加上一个函数运行时间
                    ans[st.top().first] += time - st.top().second;
                st.push(make_pair(id, time));
            } else { // end
                time ++;// 注意函数结束的计算时间需要加1 而启动的时间不用加1
                ans[st.top().first] += time - st.top().second;
                st.pop();
                if(!st.empty()) // 结束函数递归 修改上一个函数的起始时间
                    st.top().second = time;
            }
        }
        return ans;
    }
}; 
// @lc code=end

