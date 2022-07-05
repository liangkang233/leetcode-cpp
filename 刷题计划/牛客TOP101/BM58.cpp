// https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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
     * @param str string字符串 
     * @return string字符串vector
     */
    void mydfs(vector<string>& ans, string str, int index) {
        if(index >= str.size()) {
            ans.push_back(str);
        } else {
            for (int i = index; i < str.size(); i++) {
                if(i > index && str[i] == str[index])
                    continue;
                swap(str[i], str[index]);
                mydfs(ans, str, index+1);
            }
        }
    }
    vector<string> Permutation(string str) {
        vector<string> ans;
        sort(str.begin(), str.end());
        if(str.empty()) { // 坑啊 牛客输入空需要返回空
            mydfs(ans, str, 0);
        }
        return ans;
    }
};