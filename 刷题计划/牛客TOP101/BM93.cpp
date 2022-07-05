// https://www.nowcoder.com/practice/3d8d6a8e516e4633a2244d2934e5aa47?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param height int整型vector 
     * @return int整型
     */
    // 贪心双指针
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, ans = 0;
        while (l < r) {
            if(height[l] <= height[r]) {
                ans = max((r-l) * height[l++], ans);
            } else {
                ans = max((r-l) * height[r--], ans);
            }
        }
        return ans;
    }
};