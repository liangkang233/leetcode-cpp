/*
 * @lc app=leetcode.cn id=677 lang=cpp
 *
 * [677] 键值映射
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

// @lc code=start
class tireNode {
public:
    int value;
    vector<tireNode*> son;
    tireNode(): son(26), value(0){}
};

class MapSum {
private:
    tireNode* root;
public:
    MapSum() {root = new tireNode();}
    
    void insert(string key, int val) {
        tireNode* now = root;
        for (char &s : key) {
            if(!now->son[s-'a'])
                now->son[s-'a'] = new tireNode();
            now = now->son[s-'a'];
        }
        now->value = val;
    }
    int mysum(tireNode* now) {
        int s = now->value;
        for (int i = 0; i < now->son.size(); i++) {
            if(now->son[i])
                s += mysum(now->son[i]);
        }
        return s;
    }
    int sum(string prefix) {
        tireNode* now = root;
        for (char &s : prefix) {
            if(!now->son[s-'a'])
                return 0;
            now = now->son[s-'a'];
        }
        return mysum(now);
    }
};
/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

