/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */

#include <iostream>
#include <vector>
using namespace std;
// 对k位置煎饼翻转即为0-k reverser 与 ./编程之法/字符串反转.cpp区分下

// @lc code=start
class Solution {
public:
    // 由题中说明arr数组元素为1到size，所以最大值确定为max。
    // 暴力法:每一次迭代，将最大值反转至arr头，之后再翻转至尾部
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        for (int max = arr.size(); max>1; max--) {          
            if(arr[max-1] == max) //该数字无需排序
                continue;
            int temp; //临时下标
            for (temp=max; temp>0 && arr[temp-1]!=max; temp--); // 找到当前最大值，并转换至容器头
            // cout << "test" << temp << max << endl;
            if(temp-1 != 0) {
                reverse(arr.begin(), arr.begin()+temp);
                ans.push_back(temp);
            }
            reverse(arr.begin(), arr.begin()+max);// 将最大值切换至队列尾部
            ans.push_back(max);
            // for (auto &&i : arr)
            //     cout << i << " ";
            // cout << endl;  
        }
        return ans;
    }
};
// @lc code=end

// [3,2,4,1]\n
// [1,2,3]\n
// [5,3,2,1,4,6]\n
// [5,4,7,9,1,3,2,6,8]\n

class Solution {
public:
    // 由题中说明arr数组元素为1到size，所以最大值确定为max。
    // 暴力法:每一次迭代，将最大值反转至arr头，之后再翻转至尾部  至多操作2*(size-1)次
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        for (int max = arr.size(); max>1; max--) {          
            if(arr[max-1] == max) //该数字无需排序
                continue;
            int temp; //临时下标
            for (temp=max; temp>0 && arr[temp-1]!=max; temp--); // 找到当前最大值，并转换至arr头
            if(temp-1 != 0) {
                reverse(arr.begin(), arr.begin()+temp);
                ans.push_back(temp);
            }
            reverse(arr.begin(), arr.begin()+max);// 将最大值切换至arr尾部
            ans.push_back(max);
        }
        return ans;
    }
};