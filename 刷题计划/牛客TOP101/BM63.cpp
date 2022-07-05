// https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=295&tqId=23261&ru=%2Fpractice%2F7a71a88cdf294ce6bdf54c899be967a2&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int jumpFloor(int number) {
        int last = 1, now = 1, temp;
        for (int i = 2; i <= number; i++) {
            temp = now;
            now += last;
            last = temp;
        }
        return now;
    }
};