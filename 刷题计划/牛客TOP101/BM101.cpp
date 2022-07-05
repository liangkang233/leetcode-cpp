// https://www.nowcoder.com/practice/93aacb4a887b46d897b00823f30bfea1?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

struct pi {
    int k, val, f;
    pi(): k(0), val(0), f(0) {};
    pi(int a, int b, int c): k(a), val(b), f(c) {};
};

class Solution {
private:
    int cap, minN = 1;
    unordered_map<int, list<pi>> mpL;           // 频率对应链表
    unordered_map<int, list<pi>::iterator>mp;   // key对应链表元素迭代器
public:
    /**
     * lfu design
     * @param operators int整型vector<vector<>> ops
     * @param k int整型 the k
     * @return int整型vector
     */
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            int f = mp[key]->f, val = mp[key]->val;
            mpL[f].erase(mp[key]);
            if(mpL[f].empty() && f == minN)
                minN++;
            mpL[f+1].push_back(pi{key, val, f+1});
            auto it = mpL[f+1].end();
            mp[key] = --it;
            return mp[key]->val;
        }
        return -1;
    }
    void set(int key, int value){
        if(get(key) >= 0) {
            mp[key]->val = value;
        } else {
            if(mp.size() >= cap) {
                int f = mpL[minN].front().f, k = mpL[minN].front().k;
                mpL[f].pop_front();
                mp.erase(k);
            }
            mpL[1].push_back(pi{key, value, 1});
            auto it = mpL[1].end();
            mp[key] = --it;
            minN = 1;
        }
    }
    vector<int> LFU(vector<vector<int> >& operators, int k) {
        cap = k;
        vector<int> ans;
        for (int i = 0; i < operators.size(); i++) {
            if(operators[i][0] == 1) {
                set(operators[i][1], operators[i][2]);
            } else {
                ans.push_back(get(operators[i][1]));
            }
        }
        return ans;
    }
};