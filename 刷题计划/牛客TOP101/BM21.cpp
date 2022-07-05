// https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=295&tqId=23269&ru=%2Fpractice%2F96bd6684e04a44eb80e6a68efc0ec6c5&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int l = 0, r = rotateArray.size() - 1;
        while (l < r) {
            int mid = (l+r)/2;
            if(rotateArray[mid] < rotateArray[r]) {
                r = mid;
            } else if(rotateArray[mid] > rotateArray[r]) {
                l = mid+1;
            } else {
                r--; // 不确定最小值在那个区间 排除r边界
            }
        }
        return rotateArray[l];
    }
};