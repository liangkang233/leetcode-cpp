// 能看见楼的数量，高的楼会挡住矮的。
// 比如[5,3,8,3,2,5]
// 8可以看到5,3,8,3,5, 2被挡住了。
// 站在楼底看左右两侧 必定会看到自身 初始值 1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
    vector<int> buildingCount(vector<int>& buildings){
        stack<int> stk;
        int n = buildings.size();
        vector<int> res(n,1);
        for(int i = 0;i < n;i++){
            res[i] += stk.size();
            while(!stk.empty() && stk.top() <= buildings[i])stk.pop();
            stk.push(buildings[i]);
        }
        while(!stk.empty())stk.pop();
        for(int i = n - 1;i >= 0;i--){
            res[i] += stk.size();
            while(!stk.empty() && stk.top() <= buildings[i])stk.pop();
            stk.push(buildings[i]);
        }
        return res;
    }
};
