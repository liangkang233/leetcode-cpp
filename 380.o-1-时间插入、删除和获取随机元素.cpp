/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// @lc code=start
// vector 组合 map
class RandomizedSet {
public:
    vector<int> vt;
    unordered_map<int, int> mymap; // map 存储 key 为 val, value对应 vt value 下标
    RandomizedSet() {
        srand((unsigned)time(0));
    }
    bool insert(int val) {
        if(mymap.find(val) == mymap.end()) {
            vt.push_back(val);
            mymap.insert(make_pair(val, vt.size()-1));
            return true;
        }
        return false;
    }
    bool remove(int val) {
        if(mymap.find(val) != mymap.end()) {
            // cout << mymap[val] << endl;
            // vt中将删除的元素替换为back，然后删除最后一个 这样只有删除元素和 最后一个元素小标变化
            // map修改最后元素对应下标为val下标 然后map删除val元素的下标 
            int t = mymap[val];
            vt[t] = vt.back();
            mymap[vt.back()] = t;
            vt.pop_back();
            mymap.erase(val);
            return true;            
        }
        return false;
    }
    int getRandom() {
        if(vt.size() > 0)
            return vt[rand() % vt.size()];
        return -1;
    }
};