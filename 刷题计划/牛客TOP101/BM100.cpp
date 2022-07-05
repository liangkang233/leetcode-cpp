// https://www.nowcoder.com/practice/5dfded165916435d9defb053c63f1e84?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class Solution {
private:
     int cap;
     list<pair<int, int>> l;
     unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    Solution(int capacity){
         this->cap = capacity;
    }
    
    int get(int key) {
         if(mp.find(key) != mp.end()) {
               auto k = mp[key];
               int val = k->second;
               l.erase(k);
               l.push_back(pair<int, int>{key, val});
               auto it = l.end();
               mp[key] = --it;
               return val;
         }
         return -1;
    }
    
    void set(int key, int value){
         if(cap <= 0) return;
         if(get(key) >= 0) {
              mp[key]->second = value;
         } else {
               if(l.size() >= cap) {
                    int k = l.front().first;
                    l.pop_front();
                    mp.erase(k);
               }
               l.push_back(pair<int, int>{key, value});
               auto it = l.end();
               mp[key] = --it;
         }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* solution = new Solution(capacity);
 * int output = solution->get(key);
 * solution->set(key,value);
 */