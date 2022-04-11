/*
 * meituan-004. 小团的复制粘贴
 *
 * https://leetcode-cn.com/problems/TOVGD1/
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void myfun(int flag, vector<int>& A, vector<int>&B) {
    int k;
    cin >> k;
    if(flag == 2) {
        k--;
        cout << B[k] << endl;
        return;
    }
    int x, y;
    cin >> x >> y;
    x--, y--;
    k = min((int)B.size()-y, k);
    copy(A.begin()+x, A.begin()+(x+k), B.begin()+y);
}

int main () {
    int n;
    cin >> n;
    vector<int> A(n), B(n, -1);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int flag;
        cin >> flag;
        myfun(flag, A, B);
    }
}