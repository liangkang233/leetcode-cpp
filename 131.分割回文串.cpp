/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;

    bool isHui(string a) {
        int size = a.size();
        for (int i = 0; i < size / 2; i++) {
            if (a[i] != a[size - i - 1])
                return false;
        }
        return true;
    }
    // bool isHui(string a) {  //另一种判断回文的方法
    //     int i = 0, j = a.size() - 1;
    //     while (i < j) {
    //         if (a[i] != a[j])
    //             return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }

    void find(string s, int index, vector<string> temp) {
        if (index == s.size())
            ans.push_back(temp);
        for (int i = 1; index + i <= s.size(); i++) {
            if (isHui(s.substr(index, i))) {
                vector<string> temp1(temp);
                temp1.push_back(s.substr(index, i));
                find(s, index + i, temp1);
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        find(s, 0, temp);
        return  ans;
    }
};
// @lc code=end

/*
    ostream_iterator<string> os(cout, " ");
    for (auto vi = ans.begin(); vi != ans.end(); vi++) {
        std::copy(vi->begin(), vi->end(), os);
        cout << endl;
    }
    // 打印二重容器推荐写法，其中std::copy(vi->begin(), vi->end(), os);
    // 是将vi容器中的每个元素打印出来，以" "作为间隔
 */

// 参考了他人的做法，发现代码还是有很大进步空间的
// 时间：每次不必每次递归求一次size，最开始传长度参数可以减少运行时间
// 空间: 每次进行的bfs回溯时，不必要每次都生成一个新的temp1 直接删掉添加的元素就好
class Solution1 {
public:
    vector<vector<string>> ans;
    vector<string> temp;

    bool isHui(string a) {  //另一种判断回文的方法
        int i = 0, j = a.size() - 1;
        while (i < j) {
            if (a[i] != a[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void find(string s, int index, int len) {
        if (index == len)
            ans.push_back(temp);
        for (int i = 1; index + i <= len; i++) {
            if (isHui(s.substr(index, i))) {
                temp.push_back(s.substr(index, i));
                find(s, index + i, len);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        find(s, 0, size(s));
        return  ans;
    }
};

// 使用动态规划统计回文数防止过多重复计算，此例数据规模较小所以速度并没有快很多
class Solution2 {
public:
    vector<vector<int>> HuiMap;
    vector<vector<string>> ans;
    vector<string> temp;

    void find(string s, int index, int len) {
        if (index == len)
            ans.push_back(temp);
        for (int i = 1; index + i <= len; i++) {
            if (HuiMap[index][index + i - 1]) {
                temp.push_back(s.substr(index, i));
                find(s, index + i, len);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int size = s.size();
        HuiMap.assign(size, vector<int> (size, true));
        for (int i = size-2; i >= 0; i--) {
            for (int j = i + 1; j < size; j++) {
                HuiMap[i][j] = (s[i] == s[j]) && HuiMap[i + 1][j - 1];
            }        
        }
        
        find(s, 0, size);
        return  ans;
    }
};