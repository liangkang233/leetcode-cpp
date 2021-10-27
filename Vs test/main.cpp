#include <iostream>
#include <iterator>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 使用数组下标做记录
    int lengthOfLongestSubstring(string s) {
        int head = 0, maxnum = 0, num = 0, len = s.size();
        char myset[127] = { 0 };
        for (int i = 0; i < len; i++) {
            if (myset[s[i]]) { // 插入失败，说明有重复值
                // 如果大于记录最大值则更新。更新，并删除非新头内容
                if (num > maxnum)
                    maxnum = num;
                while (s[head] != s[i])
                    myset[s[head++]]--;
                num = i - head;
                head++;
            }
            else {
                num++;
                myset[s[i]]++;
            }
        }
        return num > maxnum ? num : maxnum; //防止max是默认值,或者没更新
    }
};


int main()
{
    Solution sol;
    string a = "pwwkew", b = ".*abc";
    //vector<int> nums = { 4,5,6,7,0,1,2 };
    vector<int> nums = { 8,9,2,3,4 };
    int ans = sol.lengthOfLongestSubstring(a);
    cout << ans;

    return 0;
}