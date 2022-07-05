/*
 * @lc app=leetcode.cn id=478 lang=cpp
 *
 * [478] 在圆内随机生成点
 */

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cmath>
using namespace std;

// @lc code=start
// 朴素做法  直接用半径的等分会错 会导致 圆心更容易被选中   正确答案是 0-r^2
class Solution {
#define PI 3.14159265
private:
    double s, x, y;
public:
    Solution(double radius, double x_center, double y_center) : s(radius), x(x_center), y(y_center) {}
    vector<double> randPoint() {
        // s 为随机角度 d为随机半径
        double a, b, c = (rand() % 360) * PI / 180, d = (rand() % 10000) / 10000.0 * s * s; 
        d = sqrt(d);
        a = sin(c) * d + x;
        b = cos(c) * d + y;
        return vector<double> {a, b};
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end

// mt19937 它的循环节是2^19937-1，这是一个梅森素数
// 使用 dis(0,1) 初始化后 dis(gen) 返回0到1的随机数

// 拒绝采样法
class Solution {
private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double xc, yc, r;
public:
    Solution(double radius, double x_center, double y_center): dis(-radius, radius), xc(x_center), yc(y_center), r(radius) {}
    vector<double> randPoint() {
        while (true) {
            double x = dis(gen), y = dis(gen);
            if (x * x + y * y <= r * r) {
                return {xc + x, yc + y};
            }
        }
    }
};

// 朴素按照分布函数做法
class Solution {
private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double> dis;
    double xc, yc, r;
public:
    Solution(double radius, double x_center, double y_center): dis(0, 1), xc(x_center), yc(y_center), r(radius) {}    
    vector<double> randPoint() {
        double u = dis(gen), theta = dis(gen) * 2 * acos(-1.0);
        double r = sqrt(u);
        return {xc + r * cos(theta) * this->r, yc + r * sin(theta) * this->r};
    }
};