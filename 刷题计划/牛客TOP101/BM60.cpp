// https://www.nowcoder.com/practice/c9addb265cdf4cdd92c092c655d164ca?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @return string字符串vector
     */
    void mydfs(vector<string>& ans, string& s, int n, int l) { // n代表还需配对数量 l代表未配对左括号数量
        if(n == 0 && l == 0)
            ans.push_back(s);
        else {
            if(n > 0) {
                s.push_back('(');
                mydfs(ans, s, n-1, l+1);
                s.pop_back();
            } 
            if(l > 0) {
                s.push_back(')');
                mydfs(ans, s, n, l-1);
                s.pop_back();
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        mydfs(ans, s, n, 0);
        return ans;
    }
};