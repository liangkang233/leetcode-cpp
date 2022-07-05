// https://www.nowcoder.com/practice/c5fbf7325fbd4c0ea3d0c3ea6bc6cc79?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int rob(vector<int>& nums) {
        int last = 0, now = 0, temp;
        for (int i = 0; i < nums.size(); i++) {
            temp = now;
            now = max(now, last + nums[i]);
            last = temp;
        }
        return now;
    }
};