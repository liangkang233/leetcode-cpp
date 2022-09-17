/*
 * @lc app=leetcode.cn id=1656 lang=cpp
 *
 * [1656] 设计有序流
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class OrderedStream {
private:
    int ptr = 0;
    vector<string> v;
public:
    OrderedStream(int n) {
        v.resize(n, "");
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> ans;
        idKey--;
        v[idKey] = value;
        // cout << ptr << " " << idKey << endl;
        if(ptr == idKey) {
            int r = ptr;
            while (r < v.size() && !v[r].empty()) {r++;}
            ans.insert(ans.end(), v.begin()+ptr, v.begin()+r);
            ptr = r;
            return ans;
        }
        return ans;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
// @lc code=end

