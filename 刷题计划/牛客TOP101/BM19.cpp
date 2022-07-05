// https://www.nowcoder.com/practice/fcf87540c4f347bcb4cf720b5b350c76?tpId=295&tqId=2227748&ru=%2Fpractice%2Fd3df40bd23594118b57554129cadf47b&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
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
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, ans = 0;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] <= nums[mid+1])
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};