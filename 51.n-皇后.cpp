#include <iostream>
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;
    // 自定义哈希表 列 左上向右下 右上向左下  (因为递增行的遍历所以不需要哈希表)
    vector<int> line, lr, rl;
    void myback(vector<string>& temp, int n) {
        if(temp.size() >= n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            string str(n, '.');
            int index1 = temp.size() + i,index2 = temp.size() - i + n-1; // 行下标 + 列下标; n-1 + 行下标 - 列下标
            if(line[i] == 1 || lr[index1] == 1 || rl[index2] == 1 ) //该位置无效，不设定
                continue;
            line[i] = lr[index1] = rl[index2] = 1;
            str[i] = 'Q';
            temp.push_back(str);
            myback(temp, n);
            temp.pop_back(); //回溯
            line[i] = lr[index1] = rl[index2] = 0;
            str[i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp;
        line.assign(n, 0);
        lr.assign(2*n-1, 0);
        rl.assign(2*n-1, 0);
        myback(temp, n);
        return ans;
    }
};
// @lc code=end