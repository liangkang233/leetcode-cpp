// https://www.nowcoder.com/practice/e19927a8fd5d477794dac67096862042?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * 旋转数组
     * @param n int整型 数组长度
     * @param m int整型 右移距离
     * @param a int整型vector 给定数组
     * @return int整型vector
     */
    vector<int> solve(int n, int m, vector<int>& a) {
        m %= n;
        reverse(a.begin(), a.end()-m);
        reverse(a.end()-m, a.end());
        reverse(a.begin(), a.end());
        return a;
    }
};