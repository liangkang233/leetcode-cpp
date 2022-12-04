/* 面试题 17.09. 第 k 个数
有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，
而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。

示例 1:
    输入: k = 5
输出: 9 */


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// 直接找会超时
class Solution {
public:
    int getKthMagicNumber(int k) {
        int ans = 0;
        while (k > 0) {
            ans++;
            if(ans % 2) { // 不能包含素因数2 否则该数无效
                int temp = ans;
                while (temp % 3 == 0) temp /= 3;
                while (temp % 5 == 0) temp /= 5;
                while (temp % 7 == 0) temp /= 7;
                if(temp == 1) k--;  // 只包含上三种素因数
            }
        }
        return ans;
    }
};

// 使用堆来做 由题意 符合答案的数据一定是 3X 5X 7X 类型
class Solution {
public:
    int getKthMagicNumber(int k) {
        unordered_set<int> us;
        priority_queue<int, vector<int>, greater<int>> que;
        int ans = 0;
        que.push(1);
        while (k--) {
            ans = que.top();
            que.pop();
            if(ans <= INT_MAX/3 && us.find(3 * ans) == us.end()) {
                us.insert(3 * ans);
                que.push(3 * ans);
            }
            if(ans <= INT_MAX/5 && us.find(5 * ans) == us.end()) {
                us.insert(5 * ans);
                que.push(5 * ans);
            }
            if(ans <= INT_MAX/7 && us.find(7 * ans) == us.end()) {
                us.insert(7 * ans);
                que.push(7 * ans);
            }
        }
        return ans;
    }
};