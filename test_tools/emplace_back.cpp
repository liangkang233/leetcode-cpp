/* 
* vector中emplace_back方法的用途 
* https://blog.csdn.net/qq295109601/article/details/114731079
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class stu_info {
    private:
        string name;
    public:
        stu_info(const string &name) {
            this->name = name;
            cout << "stu_info(): " << this->name << endl;
        }
        ~stu_info() {
            cout << "~stu_info(): " << this->name << endl;
        }
        stu_info(const stu_info &s) {
            this->name = s.name;
            cout << "copy constructor: " << this->name << endl;
        }
};

class stu_info1 {
    private:
        int name;
        int n1;
    public:
        stu_info1 (const int &name) : name(name), n1(0) {
            cout << "stu_info()1: " << this->name << " " << this->n1 << endl;
        } 
        stu_info1 (const int &name, const int &n1) : name(name), n1(n1) {
            cout << "stu_info()1: " << this->name << " " << this->n1 << endl;
        } 
        ~stu_info1 () {
            cout << "~stu_info()1: " << this->name << " " << this->n1 << endl;
        }
        stu_info1 (const stu_info1 &s) : name(s.name), n1(s.n1) {
            cout << "copy constructor1: " << this->name << " " << this->n1 << endl;
        }
};

int main () {
    // vector<stu_info> v;
    // v.reserve(10); // 提前加大长度 防止后续push导致大小更换元素重新复制分配
    // v.push_back(stu_info("nginx"));
    // v.push_back(stu_info("nginx1"));
    // v.push_back(stu_info("nginx2"));
    // v.emplace_back(stu_info("nginx1"));
    // v.emplace_back("redis");

    vector<stu_info1> v1;
    v1.reserve(10); // 提前加大长度
    v1.push_back(stu_info1(123));
    v1.emplace_back(567);
    return 0;
}
