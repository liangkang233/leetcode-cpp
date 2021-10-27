#include <iostream>
#include <string>

using namespace std;
int main () {
    string a = "nihao";
    cout << a<< endl;
    cout << a.size() << endl;
    for( auto &&i : a) {
        cout << i << endl;
    }
    
    a[1] = 0;
    cout << a<< endl;
    cout << a.size() << endl;
    for( auto &&i : a) {
        cout << i << endl;
    }
    return 0;
}