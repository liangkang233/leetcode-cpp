// https://www.nowcoder.com/practice/76039109dd0b47e994c08d8319faa352?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * pick candy
     * @param arr int整型vector the array
     * @return int整型
     */
    // 正反向遍历一遍 取出较大值作为糖果
    int candy(vector<int>& arr) {
        int ans = 0, temp = 1;
        vector<int> v(arr.size(), 1);
        for (int i = 1; i < arr.size(); i++) {
            if(arr[i] > arr[i-1])
                v[i] = v[i-1] + 1;
        }
        ans += max(v.back(), 1);
        for (int i = arr.size()-2; i >= 0; i--) {
            if (arr[i] > arr[i+1]) {
                temp = temp + 1;
            } else {
                temp = 1;
            }
            ans += max(temp, v[i]);
        }
        return ans;
    }
};