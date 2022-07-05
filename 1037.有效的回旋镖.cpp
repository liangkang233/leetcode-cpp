/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 *
 * [1037] 有效的回旋镖
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// 类似 149.直线上最多的点数.cpp 的做法 此处数据量较小
// 可以直接用乘法算斜率是否相等
bool isBoomerang(int** points, int pointsSize, int* pointsColSize){
    int x1 = points[0][0] - points[1][0];
    int y1 = points[0][1] - points[1][1];
    
    int x2 = points[0][0] - points[2][0];
    int y2 = points[0][1] - points[2][1];
    
    return x1 * y2 != x2 * y1; // => y2 / x2 != y1 / x1  免去除数为0苦恼
}

class Solution {
public:
    int gcd(int a, int b) { // 求最大公因数
        return b ? gcd(b, a%b) : a;
    }
    int fin(int a, int b) {
        if(a==0 && b == 0) return 0;
        else if(a==0) return 1;
        else if(b==0) return 10000;
        int flag = 1;
        if(a*b<0) flag = -1;
        // 求ab最小公约数
        a = abs(a), b = abs(b);
        int n = gcd(a, b);
        a /= n, b /= n * flag;
        cout << b << "/" << a << endl;
        return (a * 10000 + b );
    }
    // 斜率用浮点数注意 不可直接用等于 这里记录斜率化简后 a/b => 10000*a + b
    bool isBoomerang(vector<vector<int>>& points) {
        int k1 = fin(points[1][0]-points[0][0], points[1][1]-points[0][1]);
        int k2 = fin(points[1][0]-points[2][0], points[1][1]-points[2][1]);
        return (k1 && k2 && k1 != k2);
    }
};
// @lc code=end

