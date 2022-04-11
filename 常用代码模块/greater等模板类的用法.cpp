#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/* 关于greater等模板类的用法
greater<int>/less 是一个模板类，里面重载了()
// 即可以如此使用
greater<int> test;  // 实例化对象
test(a, b);         // 调用该对象的()
// 或者创建临时类并调用类的()符号
greater<int>()(a, b) */

struct greater1 {
    constexpr bool operator()(const int _Left, const int _Right) const {
        return _Left > _Right;
    }
};

bool cmp(int a,int b)
{
    return a < b;
}

class Solution {
public:
    void test() {
        vector<int>io {133, 22, 34, 444, 5};
        sort(io.begin(), io.end(), cmp);    // sort第三个参数传函数指针，在sort内比较大小会使用 cmp(a,b)
        sort(io.begin(), io.end(), greater1());    // 传参重载实现了()的类的类对象实例,这里传了个临时对象 在sort内比较大小会使用 greater1()(a,b)
        sort(io.begin(), io.end(), greater<int>());
        for(auto&& i : io) {
            cout << i << endl;
        }
    }
};


int main () {
    Solution sol;
    sol.test();
    if (greater1()(2,1)) {
        cout << "yes";
    }

    // priority_queue<int, vector<int>, cmp> mytest;
    priority_queue<int, vector<int>, greater1> mytest;//priority_queue 第三个参数传实现了()的类
    // 所以传greater时，要确保该对象的 '>' '<' 可用，例如
    // priority_queue<testClass, vector<testClass>, greater<testClass>> mytest;
    // testClass需要重载其 '>' '<' 

    return 0;
}
