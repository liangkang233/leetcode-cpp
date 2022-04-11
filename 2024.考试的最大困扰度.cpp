/*
 * @lc app=leetcode.cn id=2024 lang=cpp
 *
 * [2024] 考试的最大困扰度
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
// 被自己蠢到了, 明明是滑动窗口，超出k范围直接 左移左边界即可
class Solution {
public:
    int slideWindow (string& answerKey, int k, char ch) {
        int num = -1; //修改为连续ch的最大连续数
        for (int i = 0, j = 0; j < answerKey.size(); j++) { // 以 i右侧 j下标 为左右边界的滑动窗口
            if(answerKey[j] != ch)
                k--;
            while (k < 0 && i < answerKey.size()) { //size>=1 不必考虑i超过j的情况
                if(answerKey[i] != ch)
                    k++;
                i++;
            }
            num = max(num, j-i+1);
        }
        return num;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(slideWindow(answerKey, k, 'T'), slideWindow(answerKey, k, 'F'));
    }
};
// @lc code=end
// "TFFT"\n1
// "TFTFTTTTFFFFTFTFTFTFFFTTTTTFFFFTTFFTFFTFTFTFTFTF"\n3
// "TFTFTTTTFFFFTFTFTFTFFFTTTTTFFFFTTFFTFFTFTFTFTFTF"\n5
// "TFTFTTTTFTFTFTTTTFFFFTFTFTFTFFFTTTTTFFFFTTFFTFFTFTFTTFFFTTTTTFFFFTTFFTFTFTFFTFTFFFTTTTTTTTFTFTFTFTFTFFFTFFFFTFTFTFTFFFTTTTTFFFFFTFTFTFTFFTFTFFFTTTTTTTTFTFTFTFTFTFFFTFTFTFTFTFFFFFFFTTTFFFTTFFFFTTFFTFFTFTFTFTTTFFTFFTFTFTFTTTFFTFFTFTFTFTFTFFTFTFFFTTTTTTTTFTFTFTFTFTFFFTFTFTFTFTFFFFFFFTTTFFFTTFFFFTTFFTFFTFTFTFTTTFFTFFTFTFTFT"\n4
