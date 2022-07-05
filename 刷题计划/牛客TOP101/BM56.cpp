// https://www.nowcoder.com/practice/a43a2b986ef34843ac4fdd9159b69863?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

// 输出字典序
class Solution {
private:
    void mydfs(vector<vector<int>>& ans, vector<int> num, int index) { // num 非引用  之后递归对num的改变不会影响上层
        if(index == num.size()) {
            ans.push_back(num);
        } else {
            for (int i = index; i < num.size(); i++) { // 如此遍历 i后面的数字index 后的数字依旧正序
                if(i > index && num[i] == num[index])
                    continue;
                swap(num[i], num[index]);
                mydfs(ans, num, index+1);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int> &num) {
        vector<vector<int>> ans;
        sort(num.begin(), num.end());
        mydfs(ans, num, 0);
        return ans;
    }
};


class Solution {
private:
    vector<vector<int>> ans;
    void mydfs(vector<int>& temp, vector<int>& num, vector<int>& record) {
        if(temp.size() == num.size()) {
            ans.push_back(temp);
        } else {
            for (int i = 0; i < num.size(); i++) { // 如此遍历 i后面的数字index 后的数字依旧正序
                if(record[i] || (i>0 && num[i-1]==num[i] && !record[i-1]) )
                    continue;
                temp.push_back(num[i]);
                record[i] = 1;
                mydfs(temp, num, record);
                record[i] = 0;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<int> temp, record(num.size(), 0);
        mydfs(temp, num, record);
        return ans;
    }
};