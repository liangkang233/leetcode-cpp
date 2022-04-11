/*
 * meituan-010. 小团的默契游戏
 *
 * https://leetcode-cn.com/problems/yqj8Su/
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


// 二分 确定 L 后，暴力选择R 优化的方案是二分确定R
bool isok(vector<int>& nums, int L, int R) {
    int last = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        if(nums[i] < L || nums[i] > R) {
            if(nums[i] < last)
                return false;
            last = nums[i];
        }
    }
    return true;
}

int main () {
    int m, n;
    cin >> m >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    // L R nums[i]取值为 皆为 [1,m]
    // 翻译下: 设定区间 [L, R] 对nums中的 在[L,R] 中的值 全部删除 后是不绝对的递增序列
    int ans = 0;
    for (int L = 1; L <= m; L++) {
        // int start = L, end = m;
        int start = L, end = m+1; // 注意这里 end 要为m+1
        while (start < end) {
            int mid = (start + end) / 2;
            if(isok(nums, L, mid)) // L 固定时  R 越大 成功的可能越大  所以找寻临界点 使得刚好成立的 R
                end = mid;
            else 
                start = mid + 1;
        }
        ans += m - start + 1;
        if(start == m+1) // 说明L过大 无论什么R必定不可能成立
            break;
    }
    cout << ans << endl;
    return 0;
}


// 输入：
// 5 5
// 4 1 4 1 2
// 输出：10