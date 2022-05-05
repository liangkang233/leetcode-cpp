/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 行星碰撞
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 由题意 只有 栈内为正 右边出现负数才需要 抵消

// @lc code=start
class Solution {
public:
    // 进一步 逻辑优化
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        for (int i = 0; i < asteroids.size(); i++) {
            int temp = asteroids[i];
            while(!ans.empty() && ans.back() > 0 && temp < 0) {
                if(ans.back() < -temp) {
                    ans.pop_back();
                } else if(ans.back() == -temp) {
                    ans.pop_back();
                    temp = 0;
                } else {
                    temp = 0;
                }
            }
            if(temp != 0)
                ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end
// [-1,-2]\n
// [-2,-2,1,-2]\n
// [10,2,-5]\n

// 常规用数组来做
class Solution {
public:
    // 直接用数组做栈 
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        for (int i = 0; i < asteroids.size(); i++) {
            if(!ans.empty() && ans.back() > 0 && asteroids[i] < 0) {
                if(ans.back() > -asteroids[i]) {
                    while(!ans.empty() && ans.back()>0 && ans.back() > -asteroids[i])
                        ans.pop_back();
                    if(ans.empty() || ans.back()<0) {
                        ans.push_back(asteroids[i]);
                        continue;
                    }
                }
                if(!ans.empty() && ans.back() == -asteroids[i])
                    ans.pop_back();
            }
            else
                ans.push_back(asteroids[i]);
        }
        return ans;
    }
};

// 使用栈的原版官解
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(ast[i] > 0 || s.empty()) {
                s.push(ast[i]);
            }
            else {
                while(!s.empty() && s.top() > 0 && s.top() < abs(ast[i])) {
                    s.pop();
                }
                if(!s.empty() && s.top() == abs(ast[i])) {
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) {
                        s.push(ast[i]);
                    }
                }
            }
        }
		// finally we are returning the elements which remains in the stack.
		// we have to return them in reverse order.
        vector<int> res(s.size());
        for(int i = (int)s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};