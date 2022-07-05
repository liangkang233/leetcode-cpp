// https://www.nowcoder.com/practice/c3a6afee325e472386a1c4eb1ef987f3?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxLength(vector<int>& arr) {
        int ans = 1;
        unordered_set<int> ms;
        for (int l = 0, r = 0; r < arr.size(); r++) {
            while (ms.find(arr[r]) != ms.end()) {
                ms.erase(arr[l++]);
            } ms.insert(arr[r]);
            ans = max(r-l+1, ans);
        }
        return ans;
    }
};