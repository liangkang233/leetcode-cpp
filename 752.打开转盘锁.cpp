/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
// 切记 这种题 用bfs 才能正确 否则dfs后面到达 中间值数字可能 花的步数更少 导致结果偏大
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> myset; // 去重 和 上锁 使用同一个set记录
        for (int i = 0; i < deadends.size(); i++)
            myset.insert(deadends[i]);
        if(myset.find(target) == myset.end() && myset.find("0000") == myset.end()) {
            int depth = 0;
            queue<string> myque;
            myque.push("0000");
            myset.insert("0000");
            while (!myque.empty()) {
                int size = myque.size();
                for (int i = 0; i < size; i++) {
                    string temp = myque.front();
                    myque.pop();
                    // cout << temp << " " << depth << endl;
                    if(temp == target)
                        return depth;
                    for (int i = 0; i < 4; i++) {
                        string t = temp;
                        t[i] = (temp[i] - '0' + 1) % 10 + '0';
                        if(myset.find(t) == myset.end()) {
                            myque.push(t);
                            myset.insert(t);
                        }
                        t[i] = (temp[i] - '0' + 9) % 10 + '0';
                        if(myset.find(t) == myset.end()) {
                            myque.push(t);
                            myset.insert(t);
                        }
                    }
                }
                depth++;
            }
        }
        return -1;
    }
};
// @lc code=end
// ["0201","0101","0102","1212","2002"]\n"0000"
// ["8887","8889","8878","8898","8788","8988","7888","9888"]\n"8888"


// 这样一定按照固定顺序 不一定对 有可能最优解被锁了
// class Solution {
// private:
//     int ans = INT_MAX, tar;
//     unordered_set<int> myset, myset1;
// public:
//     void mydfs(int temp, int base, int count) {
//         if(myset.find(temp) == myset.end() && myset1.find(temp) == myset1.end()) { // 去重 和 没锁住的
//             printf("%04d, base %d, count %d\n", temp, base, count);
//             if(temp == tar) {
//                 ans=min(ans, count);
//             } else {
//                 if(tar % (10*base) == temp % (10*base)) {
//                     mydfs(temp, 10*base, count);
//                 } else {
//                     myset1.insert(temp); // 只有后base位数不同时才标记用于去重
//                     int t = temp / 10 / base * 10 * base, t1 = temp - t;
//                     // cout << temp << " " << t + (t1+base)%(10*base) << " " << t + (t1+9*base)%(10*base) << endl;
//                     mydfs(t + (t1+base)%(10*base), base, count + 1);
//                     mydfs(t + (t1+9*base)%(10*base), base, count + 1);
//                 }
//             }
//         }
//     }
//     int openLock(vector<string>& deadends, string target) {
//         for (int i = 0; i < deadends.size(); i++)
//             myset.insert(stoi(deadends[i]));
//         int temp = 0;
//         tar = stoi(target);
//         if(myset.find(tar) == myset.end())
//             mydfs(temp, 1, 0);
//         return ans==INT_MAX ? -1 : ans;
//     }
// };