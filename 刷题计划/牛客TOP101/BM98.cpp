// https://www.nowcoder.com/practice/7edf70f2d29c4b599693dc3aaeea1d31?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if(matrix.empty()) return vector<int>{};
        int m = matrix.size(), n = matrix[0].size(), x0 = 0, y0 = 0, x1 = m-1, y1 = n-1;
        int x = 0, y = 0, k = 0;
        vector<int> ans(m*n);
        while(k < ans.size()) {
            while (k < ans.size() && y <= y1) {
                ans[k++] = matrix[x][y++];
            } x0++; y--; x = x0;
            while (k < ans.size() && x <= x1) {
                ans[k++] = matrix[x++][y];
            } y1--; x--; y = y1;
            while (k < ans.size() && y >= y0) {
                ans[k++] = matrix[x][y--];
            } x1--; y++; x = x1;
            while (k < ans.size() && x >= x0) {
                ans[k++] = matrix[x--][y];
            } y0++; x++; y = y0;
        }
        return ans;
    }
};