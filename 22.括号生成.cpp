/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    // 回溯
    void dfs(vector<string>& ans, string test, int N1, int N2, int n) {
        // N1左括号数，右括号数N2，次数n    来做剪枝条件
        if(N1 > n || N2 > n || N2 > N1)
            return;
        if(N1 == n && N2 == n) {
            ans.push_back(test);
            return;
        }
        dfs(ans, test+'(', N1+1, N2, n);
        dfs(ans, test+')', N1, N2+1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, "", 0, 0, n);
        return ans;
    }
};
// @lc code=end


// 官方的回溯做法,节省string空间
class Solution1 {
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back(); //好好思考为什么要删掉
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};

// 简单实用的递归
/* class Solution2 {
        List<String> res = new ArrayList<>();
        public List<String> generateParenthesis(int n) {
            if(n <= 0){
                return res;
            }
            getParenthesis("",n,n);
            return res;
        }

        private void getParenthesis(String str,int left, int right) {
            if(left == 0 && right == 0 ){
                res.add(str);
                return;
            }
            if(left == right){
                //剩余左右括号数相等，下一个只能用左括号
                getParenthesis(str+"(",left-1,right);
            }else if(left < right){
                //剩余左括号小于右括号，下一个可以用左括号也可以用右括号
                if(left > 0){
                    getParenthesis(str+"(",left-1,right);
                }
                getParenthesis(str+")",left,right-1);
            }
        }
    } */
