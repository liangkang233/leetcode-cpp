/*
 * meituan-003. 小美的跑腿代购
 * 
 * https://leetcode-cn.com/problems/GXV5dX/
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void myfun(vector<int>& v, vector<int>& w, int m) {
    vector<pair<int, int>> ans(w.size(), make_pair(0, 0));
    for (int i = 0; i < v.size(); i++) {
        ans[i].first = v[i] + 2 * w[i];
        ans[i].second = i+1;
    }
    auto mycmp = [](pair<int, int>L, pair<int, int>R){
        if(L.first == R.first)
            return L.second < R.second;
        return L.first > R.first;
    };
    auto mycmp1 = [](pair<int, int>L, pair<int, int>R){
        return L.second < R.second;
    };
    // 理解错题意 是说在符合需求的答案里 输出最小字典序答案  所以最后还要再排一次 只根据second值来排
    sort(ans.begin(), ans.end(), mycmp); // mycmp first相同时比较 greater second 使用less符合字典序小的输出需求
    sort(ans.begin(), ans.begin()+m, mycmp1);
    for (int i = 0; i < m; i++)
        cout << ans[i].second << " ";
}

int main () {
    // int m = 2;
    // vector<int> v{5, 8, 1, 7, 6};
    // vector<int> w{10, 9, 4, 9, 10};

    int n, m;
    cin >> n >> m;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++)
        cin >> v[i] >> w[i];
    myfun(v, w, m);
}