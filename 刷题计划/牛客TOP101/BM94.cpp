// https://www.nowcoder.com/practice/31c1aed01b394f0b8b7734de0324e00f?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

// 单调栈
class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int>& arr) {
        long long ans = 0;
        stack <int> st; // 存储下标的 递减栈
        for (int i = 0; i < arr.size(); i++) {
            while (!st.empty() && arr[i] > arr[st.top()]) {
                int old_t = st.top();
                st.pop();
                if(st.empty()) break;
                // cout << arr[st.top()] << " " << arr[old_t] << " " << arr[i] << " ";
                ans += (min(arr[st.top()], arr[i]) - arr[old_t]) * (i-st.top()-1);
                // cout << (min(arr[st.top()], arr[i]) - arr[old_t]) * (i-st.top()-1) << endl;
            }
            st.push(i);
        }
        return ans;
    }
};

// 双指针
class Solution {
public:
    long long maxWater(vector<int>& arr) {
        int l = 0, r = arr.size()-1, ans = 0, ml=arr[l], mr = arr[r];
        while (l < r) {
            while (l < r && arr[l] <= mr) {
                ans += min(ml, mr) - arr[l];
                ml = max(arr[++l], ml);
            }
            while (l < r && arr[r] <= ml) {
                ans += min(ml, mr) - arr[r];
                mr = max(arr[--r], mr);
            }
        }
        return ans;        
    }
};