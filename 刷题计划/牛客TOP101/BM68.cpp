// https://www.nowcoder.com/practice/7d21b6be4c6b429bb92d219341c4f8bb?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        vector<int> dp(matrix[0]);
        for (int j = 0; j < matrix[0].size(); j++)
            dp[j] += dp[j-1];
        for (int i = 1; i < matrix.size(); i++) {
            dp[0] += matrix[i][0];
            for (int j = 1; j < matrix[0].size(); j++) {
                dp[j] = min(dp[j], dp[j-1]) + matrix[i][j];
            }
        }
        return dp.back();
    }
};