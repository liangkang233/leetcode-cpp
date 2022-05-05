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

// 法2  cin读取只有空格回车的字符串时并不会继续传入数据 可以采用cin.get 读入回车 空格等单个字符
// 这里仅仅是 读取一行串 并不需要 cin.get
    while (cin >> temp) {
        vec2.push_back(temp);
        if (cin.get() == '\n')
            break;
    }
    
// 法3 读入一行，以其作为一个string流 stringstream 输入输出皆可  istringstream 与 ostringstream 结合体
// 下面的示例 有点脱裤子放屁了
    string str;
    getline(cin, str);
    stringstream strin(str);
    while (strin >> temp) {
        vec3.push_back(temp);
    }
    

    // 使用 ostream_iterator 打印数据
    ostream_iterator<int> output(cout, ","); // 头文件 <iterator>
    copy(vec1.begin(), --vec1.end(), output);
    cout << *(--vec1.end()) << endl;

    copy(vec2.begin(), --vec2.end(), output);
    cout << *(--vec2.end()) << endl;

    copy(vec3.begin(), --vec3.end(), output);
    cout << *(--vec3.end()) << endl;



    // istream_iterator 用法  基本用不上
    double value1, value2;
    std::cout << "Please, insert two values: ";
    std::istream_iterator<double> eos;              // end-of-stream iterator
    std::istream_iterator<double> iit (std::cin);   // stdin iterator  其迭代器 自动移动添加 没有begin end之类操作

    if (iit!=eos)
        value1=*iit;
    ++iit;
    if (iit!=eos)
        value2=*iit;

    std::cout << value1 << "*" << value2 << "=" << (value1 * value2) << '\n';


    // substr 用法  arg1:起点 arg2:长度
    string str="We think in generalities, but we live in details.";
    string str2 = str.substr (3,5); // "think"
    int pos = str.find("live"); // position of "live" in str
    string str3 = str.substr (pos); // get from "live" to the end
    cout << str2 << ' ' << str3 << '\n';

    return 0;
}

// C分隔符切割字符串: strtok 
// 该函数返回被分解的第一个子字符串，如果没有可检索的字符串，则返回一个空指针。 
// strtok会将原字符串str的分隔符改为 '\0'  strtok内存储了类似静态局部变量保存上一次切割后的字符串
    #include <string.h>
    #include <stdio.h>
    int main () {
        char str[80] = "This is - www.runoob.com - website";
        const char s[2] = "-";
        char *token;
        token = strtok(str, s); 		// 获取第一个子字符串
        while( token != NULL ) {    	// 继续获取其他的子字符串
            printf( "%s\n", token );
            token = strtok(NULL, s);
        }
        return(0);
    }

// 转换字符串 C <stdlib.h>
// atof, atoi, atol, atoll 
// 或者 strtod, strtof, strtol, strtol, strtoll, strtold strtoul, strtoull
// a代表char* 为c中字符串 其他的  注意这里的 f 转出来为double类型
// itoa ltoa  其他情况可以用 sprintf 或 snprintf 转字符串
#include <stdio.h>
#include <stdlib.h>
int main () {
// 会将非数字字符串导入第二个参数 第三个参数(非浮点数才有)还可设定转换进制
    char mytest[] = "0Xff mytest";
    char *ptr;
    int i = strtol(mytest, &ptr, 16);
    // int i = strtol(mytest, nullptr, 16);
    printf("%d, str:%s", i, ptr);
    return 0;
}

// 转换字符串 C++ <string.h>
// stof, stold, stol, stoll, stoul, stoull
// s代表string 为c++中string      数字转字符串，只需to_string即可
// to_string; 
