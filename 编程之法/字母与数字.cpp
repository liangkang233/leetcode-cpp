/* 给定一个放有字符和数字的数组，找到最长的子数组，且包含的字符和数字的个数相同。
返回该子数组，若存在多个最长子数组，返回左端点下标值最小的子数组。若不存在这样的数组，返回一个空数组。

示例 1:
    输入: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"]
    输出: ["A","1","B","C","D","2","3","4","E","5","F","G","6","7"]

示例 2:
    输入: ["A","A"]
    输出: []

提示：
    array.length <= 100000
来源：力扣（LeetCode）链接：https://leetcode-cn.com/problems/find-longest-subarray-lcci
 */

// 利用前缀相差值来求

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int count = 0, start = -2, max = 0;
        const int len = array.size();
        int* record = new int [2 * len + 1];
        for (int i = 0; i < 2 * len + 1; i++)
            record[i] = 0x7FFFFFFF;
        record[len] = -1;

        for(int i = 0; i < len; i++) {
            if (array[i].at(0) <= '9') 
                count++;
            else 
                count--;
            if (i < record[len + count])   //只记录相差值表中第一次出现(最小)的下标
                record[len + count] = i;
            else {
                if (i - record[len + count] > max) {
                    max = i - record[len + count];
                    start = record[len + count];
                }
            }
        }
        delete [] record;
        if (start == -2) 
            return vector<string> {}; 
        else {
            start++;
            return vector<string> (array.begin() + start, array.begin() + start + max ); 
        }
    }
};

// 使用无序map代替数组
class Solution1 {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        unordered_map<int ,int> posDigitCharCha;
        int digitCnt = 0;
        int charCnt = 0;
        int mostLen = 0;
        int mostPos = 0;

        posDigitCharCha[0] = -1;
        for (int i = 0; i < array.size(); i++) {
            if (isdigit(array[i][0])) {
                digitCnt++;
            } else {
                charCnt++;
            }
            int cha = digitCnt - charCnt;
            if (posDigitCharCha.find(cha) == posDigitCharCha.end()) {
                posDigitCharCha[cha] = i;
            } else if (i - posDigitCharCha[cha] > mostLen) {
                mostLen = i - posDigitCharCha[cha];
                mostPos = posDigitCharCha[cha] + 1;
            }
        }
        return vector<string> (array.begin() + mostPos, array.begin() + mostPos + mostLen);
    }
}; 

int main()
{
    Solution su;
    vector<string> test1 = {"A","1","B","C","D","2","3","4","E","5","F","G","6","7","H","I","J","K","L","M"};
     vector<string> test2 = {"A","A"};
     vector<string> test3 = {"A","1","B","C","D","2","3","4","E","5"};

    vector<string> temp;
    //temp.reserve(100000);
    //temp.resize(100000);

    temp = su.findLongestSubarray(test1);
    for (vector<string>::iterator it = temp.begin(); it != temp.end(); ++it) {
        cout <<  *it;
    }
    cout << endl;


    //std::ostream_iterator<string> dataIter(std::cout, ", ");
    //std::copy(su.findLongestSubarray(test1).begin(), su.findLongestSubarray(test1).end(), dataIter);

     temp = su.findLongestSubarray(test2);
     for (int i = 0; i < temp.size(); i++) {
         cout <<  temp[i];
     }
     cout << endl;

     temp = su.findLongestSubarray(test3);
     for (int i = 0; i < temp.size(); i++) {
         cout <<  temp[i];
     }
     cout << endl;

    return 0;
}