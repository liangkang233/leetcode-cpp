/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0, j=0;
        bool flag = false;
        while (j < typed.size()) {            
            if(name[i] == typed[j]) { // 优先走i的值
                if (i < name.size() - 1)
                    i++;
                else
                    flag = true;
                j++;
            }
            else {
                if(j > 0 && typed[j-1] == typed[j])
                    j++;
                else
                    return false;
            }
        }
        // cout << i << name[i] << endl;
        return flag;//防止i没跑完
    }
};
// @lc code=end

// 优化下：
class Solution1 {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0, j=0;
        while (j < typed.size()) {            
            if(i < name.size() && name[i] == typed[j]) { // 优先走i的值
                i++;
                j++;
            }
            else if (j > 0 && typed[j-1] == typed[j])
                j++;
            else 
                return false;
        }
        return i == name.size();//防止i没跑完
    }
};
