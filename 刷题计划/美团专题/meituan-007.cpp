/*
 * meituan-007. 小团的选调计划
 *
 * https://leetcode-cn.com/problems/SDRaNt/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<vector<int>> nums(n, vector<int>(n));
    unordered_set<int> myset;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> nums[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(myset.find(nums[i][j]) == myset.end()) {
                cout << nums[i][j] << " ";
                myset.insert(nums[i][j]);
                break;
            }
        }
    }
    return 0;
}

// 输入:
// 5
// 1 5 3 4 2 
// 2 3 5 4 1 
// 5 4 1 2 3 
// 1 2 5 4 3 
// 1 4 5 2 3
// 输出:
// 1 2 5 4 3