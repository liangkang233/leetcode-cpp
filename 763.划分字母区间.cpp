/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans; // 为了划分最大化，贪心遍历 未初始化的字符设定为 新的下标左界
        vector<int> mymap(26, -1); // 26个字母 对应的区间左界 -1 表示该字符未统计过
        for (int i = 0; i < s.size(); i++) {
            if(mymap[s[i] - 'a'] == -1)
                mymap[s[i] - 'a'] = i; // 该字符的区间左界即为下标
            else {
                int temp = mymap[s[i] - 'a']; // 合并区间
                for (int j = i; j > temp; j--)
                    mymap[s[j] - 'a'] = temp;
            }
        }
        int temp = 0;
        for (int i = 1; i < s.size(); i++) { // 再遍历一次取出区间长度
            if(mymap[s[i] - 'a'] != temp) {
                ans.push_back(mymap[s[i] - 'a'] - temp);
                temp = mymap[s[i] - 'a'];
            }
        }
        ans.push_back(s.size() - temp);
        return ans;
    }
};
// @lc code=end
// "ashdhfiahiurghhakjghjhsdjghjahdajsdkjgiouahweriogasdkjhfjkaeklrhoweuwokjapwosdvjzjkxhcguhsrukfghksjhkjaowuehfdjkanvbdjvsjghkajhgj"\n
// "adfheyazxcvbnmlkjgrtutis"\n
// "aaaagdfuhudfghiudifguhiufgihuiehrjbja"\n


// 官方做法 从右界 记录 少进行最后的整合遍历
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        int length = s.size();
        for (int i = 0; i < length; i++) {
            last[s[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};

// 二刷
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int mymap[26]; // 可以不用初始化 没遍历到的值第2次遍历也不会取到
        for (int i = 0; i < s.size(); i++)
            mymap[s[i] - 'a'] = i;
        int temp = -1, count = 0;
        for (int i = 0; i < s.size(); i++) {
            temp = max(temp, mymap[s[i] - 'a']);
            count++;
            if(i == temp) {
                ans.push_back(count);
                count = 0;
            }
        }
        return ans;
    }
};