// https://www.nowcoder.com/practice/6fe0302a058a4e4a834ee44af88435c7?tpId=295&tqId=23261&ru=%2Fpractice%2F6d29638c85bb4ffd80c020fe244baf11&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param cost int整型vector 
     * @return int整型
     */
    int minCostClimbingStairs(vector<int>& cost) {
        int last = 0, now = 0, temp;
        for (int i = 2; i <= cost.size(); i++) {
            temp = now;
            now = min(now + cost[i-1], last + cost[i-2]);
            last = temp;
        }
        return now;
    }
};