// https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int now = array[0], ans = now;
        for (int i = 1; i < array.size(); i++) {
            now = max(array[i], array[i] + now);
            ans = max(now, ans);
        }
        return ans;
    }
};