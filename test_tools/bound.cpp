#include <iostream>     // std::cout
#include <algorithm>    // std::upper_bound
#include <vector>       // std::vector
using namespace std;

//以普通函数的方式定义查找规则 等价operator
bool mycomp(int i, int j) { return i > j; }
auto mycomp1 = [](int i, int j)->bool { return i > j; };

class mycomp2 {
public:
    bool operator()(const int& i, const int& j) {
        return i<j;
    }
};

int main() {
	int x = 1;
    int a[5] = { 1,2,3,4,5 };
    // 找不到对应值时会返回 vector.end() 若是输入指针则返回-1的地址
    int *p = upper_bound(a, a + 5, x);
    cout << "*p = " << *p << endl;
    p = lower_bound(a, a + 5, x);
    cout << "*p = " << *p << endl;

    // 以函数对象的形式定义查找规则 j为容器遍历值 i为输入的查找值
    // low是找出大于等于指定值，即找出i>=j才停 i是遍历值 函数内不成立跳出循环
	vector<int> myvector{ 1,2,3,4,5 };
    vector<int>::iterator iter = upper_bound(myvector.begin(), myvector.end(), x, mycomp2());
    if(iter==myvector.end())
    	cout << "error"<<endl;
    else
    	cout << "*iter = " << *iter;


    // uper找出大于指定值，即找出j>i才停 j是遍历值 函数内成立跳出循环
    // 以函数对象的形式定义查找规则 i为容器遍历值 j为输入的查找值
    vector<int>::iterator iter = upper_bound(myvector.begin(), myvector.end(), x, mycomp2());
    if(iter==myvector.end())
    	cout << "error"<<endl;
    else
    	cout << "*iter = " << *iter;
    return 0;
}
