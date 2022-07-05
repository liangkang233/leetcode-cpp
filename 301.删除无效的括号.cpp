/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
private:
    int N = 0;
    unordered_set<string> ans;
public:
    void mydfs(const string& s, string& temp, int i, int nL, int nR) { // 当前index 以及未使用的(数量 配对括号数量
        if(i == s.size()) {
            if(nL == 0 && nR == N)
                ans.insert(temp);
        }
        else if(s[i] == '(' || s[i] == ')') {
            if(s[i] == '(' && nL < N) {  // 添加 字符 (
                temp.push_back(s[i]);
                mydfs(s, temp, i+1, nL+1, nR);
                temp.pop_back();
            }
            if(s[i] == ')' && nL > 0) { // 添加 字符 )
                temp.push_back(s[i]);
                mydfs(s, temp, i+1, nL-1, nR+1);
                temp.pop_back();
            }
            if(s.size() - i >= 2*(N-nR) - nL) // 字符过少无需递归下去
                mydfs(s, temp, i+1, nL, nR);  // temp不包含该字符
        } else { // 其他字符一定包含
            temp.push_back(s[i]);
            mydfs(s, temp, i+1, nL, nR);
            temp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string temp;
        // 首先计算最多几对有效括号
        for (int i = 0, n = 0; i < s.size(); i++) {
            if(s[i] == '(')
                n++;
            else if(s[i] == ')' && n > 0) {
                n--;
                N++;
            }
        }
        // cout << N << "对括号" <<  endl;
        mydfs(s, temp, 0, 0, 0);
        return vector<string>{ans.begin(), ans.end()};
    }
};
// @lc code=end
// "(())()()))()()"\n
// "ks((()))()(()dj()((()(erh"\n


// 官方的bfs  效果还不如我上面的写法
// 这样的描述正是广度优先搜索算法应用的场景，并且题目也要求我们输出所有的结果。
// 我们在进行广度优先搜索时每一轮删除字符串中的 1 个括号，
// 直到出现合法匹配的字符串为止，此时进行轮转的次数即为最少需要删除括号的个数。
class Solution {
public:
    bool isValid(string str) { // 判断左右括号是否有效
        int count = 0;
        for (char c : str) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) {
                    return false;
                }
            }
        }
        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> currSet;
        currSet.insert(s);
        while (true) { // bfs下去 每组数据都为上一组的str只删除一个[ 或 ] 直到出现第一组有效值
            for (auto & str : currSet) {
                if (isValid(str))
                    ans.emplace_back(str);
            }
            if (ans.size() > 0) return ans;

            unordered_set<string> nextSet;
            for (auto & str : currSet) {
                for (int i = 0; i < str.size(); i++) {
                    if (str[i] == '(' || str[i] == ')') {
                        // substr 哪怕个数超出也会确保 string 不越界  
                        // 此处 nextstr 为 删除i下标字符 且该字符为 [ 或 ]
                        nextSet.insert(str.substr(0, i) + str.substr(i + 1, str.size()));
                    }
                }
            }
            currSet = nextSet;
        }
    }
};