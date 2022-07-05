// https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k == 0 || input.size() < k)  return vector<int>{};
        priority_queue<int> que; // 大根堆
        vector<int> ans(k);
        for (int i = 0; i < input.size(); i++) {
            if(que.size() < k) {
                que.push(input[i]);
            } else {
                if(que.top() > input[i]) {
                    que.pop();
                    que.push(input[i]);
                }
            }
        }
        for (int i = 0; i < k; i++) {
            ans[i] = que.top();
            que.pop();
        }
        return ans;
    }
};