/*
 * meituan-006. 小团的神秘暗号
 *
 * https://leetcode-cn.com/problems/z3XKBp/
 */
#include <iostream>
#include <string>
using namespace std;

// 头部字符串 T结尾  尾部字符串 M开头
// 翻译翻译题目 什么TM的叫解码 => 
// 找出串中 第一个xxMxT 的 T 位置
// 找出串中 最后一个MxTxx 的 M 位置
void myfun(int N, string& strs) {
    int begin = 0, end = 0, i = 0;
    while (strs[i] != 'M' ) i++;
    while (strs[i] != 'T' ) i++;
    begin = ++i;
    for (int temp = end; i < N; i++) {
        if(strs[i] == 'M')
            temp = i;
        else if(strs[i] == 'T')
            end = temp;
    }
    cout << strs.substr(begin, end - begin) << endl;
}
int main () {
    int N;
    string strs;
    cin >> N >> strs;
    myfun(N, strs);
    return 0;
}
// string a = "TMTDJSKMT";
// 10\n"TMTDJSKMT"
// 11\n"TMTDJSKMTM"

// 清爽的很 不用遍历中间的数据
int main(){
    int n;
    string raw;
    cin >> n >> raw;
    int le = 0, ri = n-1;

    while(raw[le] != 'M') le++;
    while(raw[le] != 'T') le++;
    while(raw[ri] != 'T') ri--;
    while(raw[ri] != 'M') ri--;
    le++; ri--;
    cout << raw.substr(le, ri -le + 1);
}