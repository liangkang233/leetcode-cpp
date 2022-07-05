// https://www.nowcoder.com/practice/4bcf3081067a4d028f95acee3ddcd2b1?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
private:
    void mydfs(vector<vector<int>>& ans, vector<int>& num, int index) {
        if(index == num.size()) {
            ans.push_back(num);
        } else {
            for (int i = index; i < num.size(); i++) {
                swap(num[i], num[index]);
                mydfs(ans, num, index+1);
                // swap(num[i], num[index]); // 可以不用还原回去
            }
        }
    }
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> ans;
        mydfs(ans, num, 0);
        return ans;
    }
};