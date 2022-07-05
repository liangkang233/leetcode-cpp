#include <iostream>
#include <string>
#include <algorithm>
// #include <vector>
using namespace std;

// 蓝桥杯中带分数使用到这些思想
// 或者直接使用 next_permutation
/* 对于 next_permutation 函数，其函数原型为：
    #include <algorithm>
    bool next_permutation(iterator start,iterator end)
当当前序列不存在下一个排列时，函数返回false，否则返回true */

// 此方法未改变原字符串，要做任何处理时加在else外即可（重复字符的输出排列存在重复）
void StrAll(string str, int start, int end)     //全排列递归法(非字典序)  
{
    if (end <= 1)
        return ;
    else if(start >= end) {
        for (int i = 0; i < end; i++)
            cout << str[i];
        cout << endl;   
    }
    else {
        for (int i = start; i < end; i++) {
            swap(str[start], str[i]);
            StrAll(str, start+1, end);
            swap(str[i], str[start]);
        }
    }
}

// 此方法使用了引用，每次排列会改变原字符串，使用更加灵活可以面对重复字符无重复排列 （推荐）
bool CalcAllPermutation(string& perm, int num){   //全排列字典序
    
    int i, k;
    //①找到排列中最后（最右）一个升序的首位位置i，x = ai   (说明之后的一定是降序 之后的翻转就可变为升序)
    for (i = num - 2; i>=0 && perm[i] >= perm[i + 1]; --i) ;
    if (i < 0)
        return false;

    //②找到排列中第i位右边最后一个比ai 大的位置j，y = aj
    for (k = num - 1; (perm[k] <= perm[i]); --k) ;

    //③交换x，y
    swap(perm[i], perm[k]);
    //④把第(i+ 1)位到最后的部分翻转
    reverse(perm.begin() + i + 1, perm.end());
    cout << perm << endl;
    return true;
}

int main ()
{
    string str;
    cin >> str;     //输入一个不重复的字符串

    // 递归法
    // cout << "全部排列为：" << endl;
    // cout << str << " size :" << str.size() << endl;
    // StrAll(str, 0, str.size());

    // 字典法
    sort(str.begin(), str.end());
    cout << str << endl;
    while ( CalcAllPermutation(str, str.size()) ) ;

    return 0;
}