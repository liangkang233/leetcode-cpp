// https://www.nowcoder.com/practice/345e2ed5f81d4017bbb8cc6055b0b711?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int>> ans;
        for (int i = 0; i < (int)num.size()-2 && num[i] <= 0; i++) { // 注意size-2 可能为负数 且size为无符号数，需要强转
            int l = i+1, r = num.size()-1, t = -num[i];
            if(num[r] + num[r-1] < t || (i > 0 && num[i-1] == num[i])) continue;
            while (l < r) {
                if(num[l] + num[r] <= t) {
                    if(num[l] + num[r] == t)
                        ans.push_back(vector<int>{num[i], num[l], num[r]});
                    while (l < r && num[l+1] == num[l]) {l++;}
                    l++;
                } else {
                    while (l < r && num[r-1] == num[r]) {r--;}
                    r--;
                }
            }
        }
        return ans;
    }
};