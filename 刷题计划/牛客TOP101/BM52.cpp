// https://www.nowcoder.com/practice/389fc1c3d3be4479a154f63f495abff8?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        int ans = 0, ans1 = 0, k;
        for (int i = 0; i < array.size(); i++) ans ^= array[i];
        k = ans & -ans; // k为ans最后一位1 用于分割为两组数字
        for (int i = 0; i < array.size(); i++) {
            if(array[i] & k)
                ans1 ^= array[i];
        }
        ans ^= ans1;
        if(ans > ans1)
            swap(ans, ans1);
        return vector<int> {ans, ans1};
    }
};