/*
 * @lc app=leetcode.cn id=1823 lang=cpp
 *
 * [1823] 找出游戏的获胜者
 */

#include <algorithm>
#include <iostream>
#include <iostream>
#include <stack>
#include <list>
using namespace std;


// @lc code=start
class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k==1) return n;
        int index = 0;
        list<int> mylist;
        for (int i = 1; i <= n; i++)
            mylist.push_back(i);
        while(mylist.size() > 1) {
            index = (index -1 + k) % mylist.size(); // k-1是因为元素消除 下标需要减少
            list<int>::iterator it = mylist.begin();
            for (int i = 0; i < index; i++) it++;
            cout << *it << endl;
            mylist.erase(it);
        }
        return mylist.front();
    }
};
// @lc code=end
// 234 4

// 约瑟夫环——公式法 动态规划（递推公式） https://blog.csdn.net/u011500062/article/details/72855826
// f(N,M) = ( f(N−1,M) + M ) % N 
// f(N,M) 表示，N个人报数，每报到 M 时杀掉那个人，最终胜利者的编号
class Solution {
public:
    int findTheWinner(int n, int k) {
        int p = 0;
        for (int i = 2; i <= n; i++) {
            p = (p + k) % i;
        }
        return p + 1; // p为下标 实际编号为 下标p+1
    }
};
