/*
 * meituan-005. 小美的区域会议
 * 
 *
 * https://leetcode-cn.com/problems/Uo7Dr5/
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int base = 1e9 + 7;
int n, k, root, ranks;

int myfun(vector<vector<int>>& link, vector<int>& priority, vector<bool>& myset, int index) {
    if(priority[index] < ranks || priority[index] > ranks + k)
        return 0;
    if(priority[index] == ranks && index < root) // 同ranks的要去重，类似90题的回溯 只记录 下标比root大 只要选中的否则放弃
        return 0;
    long long count = 1;
    myset[index] = true;
    for (int i = 0; i < link[index].size(); i++) {
        if(!myset[link[index][i]]) {
            count *= (1 + myfun(link, priority, myset, link[index][i]));
            count %= base;
        }
    }
    myset[index] = false;
    return count;
}

int main () {
    cin >> n >> k;
    vector<vector<int>> link(n);
    vector<int> priority(n);
    vector<bool> myset(n, false); // 记录是否遍历过
    for (int i = 0; i < n-1; i++) { // 建图
        int a, b;
        cin >> a >> b;
        --a, --b;
        // link[--a].push_back(--b);
        link[a].push_back(b);
        link[b].push_back(a);
    }
    for (int i = 0; i < n; i++) // 记录优先级
        cin >> priority[i];
    int ans = 0;
    for (int i = 0; i < n; i++) { // 遍历回溯
        myset[i] = true;
        root = i, ranks = priority[i];
        ans += myfun(link, priority, myset, i);
        ans %= base;
        myset[i] = false;
        // cout << ans << " ";
    }
    // cout << endl;
    cout << ans << endl;
    return 0;
}

// 5 1
// 1 2
// 2 3
// 3 4
// 4 5
// 2 2 2 2 2
// 输出：15
// 解释：显然一个区域负责人的方案有 {1}，{2}，{3}，{4}，{5} 共5个，(这个案例中 这五个人都能召集全部人)
// 召集到两个人的方案有 4 个，召集到三个人的方案有 3 个，召集到四个人的方案有 2 个，召集到五个人的方案有 1 个，共 15 个。

// 注意！！ 题目并不要要求每个方案能够召集所有人 且所有方案的负责人只要一个即可
// 对于每个结点 i，我们取出含有结点 i，以它为召集区间内的最小秩值
// 即值在 [A[i],A[i]+k] 内的子树，然后计算该子树（连通图）中含有节点 i 的方案数。
// 如果该子树只有一个节点，那么就只有一个方案。
// 如果它有 m 个子节点，那么递归计算子节点的方案数（在子树的基础上）。假设第 j 个子树的方案数为 dp[j]，
// 这棵子树的选择情况为：不选该子树、选该子树方案。
// 不选的有 1 种，选的有 dp[j] 种。总的方案数为 (dp[0] + 1)(dp[1] + 1)...(dp[m - 1] + 1)(dp[0]+1)(dp[1]+1)...(dp[m−1]+1)。

// 在计算『ans』时，我们可以发现其递推公式为 ans = ans + ans * dfs(next, start)，具体编码时加上取模操作即可。

// 此外，如果level相等，例如题目给定的示例，我们可以限定下一节点的『序号』必须大于起始节点，避免重复计算。 即90题的递归去重一样的思路

// 5 1
// 1 2
// 2 3
// 3 4
// 4 5
// 1 3 5 7 9