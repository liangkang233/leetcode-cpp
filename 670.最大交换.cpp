/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        string n = to_string(num);
        priority_queue<char> que;
        for(int i = 0; i < n.size(); i++) que.push(n[i]);
        for(int i = 0; i < n.size(); i++) {
            // cout << que.top() << endl;
            if(que.top() == n[i]) {
                que.pop();
            } else {
                int t = i, j = n.size()-1;
                for(; j > i; j--) {
                    if(n[j] > n[t]) {
                        t = j;
                    }
                }
                swap(n[i], n[t]);
                break;
            }
        }
        return stoi(n);
    }
};
// @lc code=end

