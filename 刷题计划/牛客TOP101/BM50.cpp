// https://www.nowcoder.com/practice/20ef0972485e41019e39543e8e895b7f?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int>mp;
        for (int i = 0; i < numbers.size(); i++) {
            if(mp.find(target - numbers[i]) != mp.end())
                return vector<int> {mp[target - numbers[i]] + 1, i + 1};
            mp[numbers[i]] = i;
        }
        return vector<int>{-1, -1};
    }
};