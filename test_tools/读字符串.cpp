#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include <iterator>
#include <sstream>

using namespace std;

// 功能： 读入一行字符串，将其中以空格分隔的数字读入并存入容器中

int main () {

    int temp;
    vector <int> vec1, vec2, vec3;

// 法1 使用scanf c的方法
    char c_str;
    do {
    scanf("%d%c", &temp,&c_str);
    // printf("test %d\n", temp);
    vec1.push_back(temp);
    }
    while (c_str == ' ') ;

// 法2  类似法1 使用cin.get 读入
    while (cin >> temp) {
        vec2.push_back(temp);
        if (cin.get() == '\n')
            break;
    }
    
// 法3 读入一行，以其作为一个string流
    string str;
    getline(cin, str);
    stringstream strin(str);
    while (strin >> temp) {
        vec3.push_back(temp);
    }
    

    // 使用ostream打印数据
    ostream_iterator<int> output(cout, ",");
    copy(vec1.begin(), --vec1.end(), output);
    cout << *(--vec1.end()) << endl;

    copy(vec2.begin(), --vec2.end(), output);
    cout << *(--vec2.end()) << endl;

    copy(vec3.begin(), --vec3.end(), output);
    cout << *(--vec3.end()) << endl;


    return 0;
}