/*
 * meituan-002. 小美的仓库整理
 *
 * https://leetcode-cn.com/problems/TJZLyC/
 */

#include <cstdio>
#include <cstring>
#include <map>
#include <set>

// 思路类似 也是暴力出来的 这个好 用的map排序
// https://leetcode-cn.com/problems/TJZLyC/solution/zhe-bu-bao-li-yi-bo-ma-qian-zhui-he-ying-vh9h/

int main() {
    int prefix[50050];
    std::map<int, int> mymap; // mymap key为区间和 value为该区间和对应的个数
    std::set<int> bound;   // 记录所有区间的左右边界 对于初始区间为1-n (左开右开) bound 插入 0 n+1 所有提取数据刚好会填满 set 0 -> n+1

    int n, w;
    scanf("%d", &n);
    memset(prefix, 0, sizeof(prefix));
    for (int i = 0; i < n; i++) {
        scanf("%d", &w);
        prefix[i + 1] = prefix[i] + w;
    }

    int pos;
    bound.insert(0);
    bound.insert(n + 1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos);
        auto idx = bound.lower_bound(pos);
        // set 的迭代器只能 自加 或 自减
        int right = *idx, left = *(--idx);
        int seg = prefix[right - 1] - prefix[left];
        if (mymap.find(seg) != mymap.end()) {
            if (mymap[seg] == 1) {
                mymap.erase(seg);
            } else {
                mymap[seg]--;
            }
        }
        bound.insert(pos);
        if(pos-1 != left) // 空区间 没必要insert
            mymap[prefix[pos - 1] - prefix[left]]++;
        if(right-1 != pos)// 空区间 没必要insert
            mymap[prefix[right - 1] - prefix[pos]]++;
        if(!mymap.empty())
            printf("%d\n", mymap.rbegin()->first);
        else
            printf("%d\n", 0);
    }
    // for (auto &&i : mymap)
    //     std::cout << i.first << i.second << std::endl;
    return 0;
}


// 明白了它的思路后 其实还可以优化下, 只要用 排序set 记录 所有数据组即可 没必要添加map
// 就是我原来的思路 只不过边界可以用set来做 而不是vector




/* 
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

// 做是可以做出来的， 就是这个pair的二分中 比较函数会比第二个second元素 导致出错
// 思路: 每次挑选货物 记录区间变化 各货物和区间和用 multiset 排序查询
void mysolution(vector<int>& w, vector<int>& test) {
    vector<int> prefix(w.size() + 1, 0); // 前缀和数组
    vector<pair<int, int>> index{ make_pair(0, w.size() - 1) }; // 区间记录
    multiset<int> myset; // 排序set 记录当前的货物重量
    for (int i = 0; i < w.size(); i++)
        prefix[i + 1] = prefix[i] + w[i];
    myset.insert(prefix.back());

    for (int i = 0; i < test.size(); i++) {
        auto it = upper_bound(index.begin(), index.end(), make_pair(test[i], test[i])) - 1; //二分查找对应区间
        int temp1 = prefix[it->second + 1] - prefix[it->first];
        myset.erase(myset.find(temp1));
        if (it->first == test[i] || it->second == test[i]) { // 单个区间变化
            if (it->first == test[i])
                it->first++;
            else
                it->second--;
            temp1 -= w[test[i]];
            if (temp1) // 区间为空没必要插入0
                myset.insert(temp1);
            else
                index.erase(it);
        }
        else { // 拆分为两个区间
            myset.insert(prefix[it->second + 1] - prefix[test[i] + 1]);
            myset.insert(prefix[test[i]] - prefix[it->first]);
            int t = it->second;
            it->second = test[i] - 1;
            index.insert(it + 1, make_pair(test[i] + 1, t)); // 插入元素后 容器it会失效 只能后插入
        }
        //for (auto &&i : myset)
        //    cout << i << " ";
        //cout << endl;
        if (myset.empty())
            cout << "0" << endl;
        else
            cout << *myset.rbegin() << endl;
    }
}


int main() {
    vector<int> w{ 2, 5, 4, 12, 34, 47, 54, 62, 22, 3, 12, 11 };
    // vector<int> w{3, 2, 4, 4, 5};
    // vector<int> test{3, 2, 4, 1, 0};
    vector<int> test{ 10, 1, 3, 7, 8, 11, 2, 6, 0, 4, 5, 9 };


    // int T;
    // cin >> T;
    // vector<int> w(T), test(T);
    // for (int i = 0; i < T; i++)
    //     cin >> w[i];
    // for (int i = 0; i < T; i++) {
    //     cin >> test[i];
    //     test[i]--;
    // }

    //for (auto &&i : test)
    //    cout << i << endl;
    mysolution(w, test);
    return 0;
}

// 12
// 2 5 4 12 34 47 54 62 22 3 12 11
// 11 2 4 8 9 12 3 7 1 5 6 10 */