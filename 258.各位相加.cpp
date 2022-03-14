/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // O(1) 时间复杂度实现
    // https://leetcode-cn.com/problems/add-digits/solution/ge-wei-xiang-jia-by-leetcode-solution-u4kj/
    int addDigits(int num) {
        if(num==0)
            return 0;
        if(num % 9 == 0)
            return 9;
        return num % 9;
        // 想不到这个做法
        // return (num - 1) % 9 + 1;
    }

};
// @lc code=end

// 0\n
// 123432550\n

// 常规递归法
int addDigits(int num) {
    int s = 0;
    while(num != 0){
        s += num % 10;
        num /= 10;
    }
    if(s < 10)
        return s;
    return addDigits(s);
}

// 常规迭代法
int addDigits(int num) {
    while (num >= 10) {
        int s = 0;
        while(num != 0){
            s += num % 10;
            num /= 10;
        }
        num = s;
    }    
    return num;
}