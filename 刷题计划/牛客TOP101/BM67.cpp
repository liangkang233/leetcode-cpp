// https://www.nowcoder.com/practice/166eaff8439d4cd898e3ba933fbc6358?tpId=295&tqId=685&ru=%2Fpractice%2Ff33f5adc55f444baa0e0ca87ad8a6aac&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param m int整型 
     * @param n int整型 
     * @return int整型
     */
    // 即为求 Cn-1 m+n-2
    int uniquePaths(int m, int n) {
        if(n > m) swap(m, n);
        long long ans = 1, t = m+n-2;
        for (int i = 1; i < n; i++, t--) {
           ans = ans * t / i;
            cout << ans << endl;
        }
        return ans; 
    }
};