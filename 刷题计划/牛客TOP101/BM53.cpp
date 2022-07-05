// https://www.nowcoder.com/practice/50ec6a5b0e4e45348544348278cdcee5?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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
    int minNumberDisappeared(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int t = nums[i];
            // 迭代替换 防止类似 [3,4,-1,1] 例子中 前面的篡改了后面的元素而没有继续修改下去
            while (t > 0 && t <= nums.size() && nums[t-1] != t) {
                int t1 = nums[t-1];
                nums[t-1] = t;
                t = t1;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == i+1)
                continue;
            return i+1;
        }
        return nums.size() + 1;
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int minNumberDisappeared(vector<int>& nums) {
        unordered_set<int> ms(nums.begin(), nums.end());
        for (int i = 1; i <= nums.size(); i++) {
            if(ms.find(i) == ms.end())
                return i;
        }
        return nums.size() + 1;
    }
};