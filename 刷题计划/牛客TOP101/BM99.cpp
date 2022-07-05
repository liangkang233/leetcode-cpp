// https://www.nowcoder.com/practice/2e95333fbdd4451395066957e24909cc?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;



// 先对称交换 再水平交换即可
class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i-1; j >= 0; j--)
                swap(mat[i][j], mat[j][i]);
        }
        for (int i = 0; i < n; i++)
            reverse(mat[i].begin(), mat[i].end());
        return mat;
    }
};

// 逆时针90度
class Solution {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = i-1; j >= 0; j--)
                swap(mat[i][j], mat[j][i]);
        }
        for (int l = 0, r = mat.size()-1; l < r; l++, r--)
            swap(mat[l], mat[r]);
        return mat;
    }
};

