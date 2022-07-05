// https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int ans = -1, count = 0;
        for (int i = 0; i < numbers.size(); i++) {
            if(count == 0) 
                ans = numbers[i];
            if(ans == numbers[i])
                count++;
            else
                count--;
        }
        return ans;
    }
};