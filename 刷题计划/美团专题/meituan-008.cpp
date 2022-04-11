/*
 * meituan-008. 小团无路可逃
 *
 * https://leetcode-cn.com/problems/vSYUMc/
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

void myfun(vector<vector<int>>& adjoin, int start, vector<int>& dist) { // 由题意 结构为树 必定找得到路
    queue<int> myque;
    myque.push(start);
    while (!myque.empty()) {
        int now = myque.front();
        myque.pop();
        for (int i = 0; i < adjoin[now].size(); i++) {
            if(dist[ adjoin[now][i] ] == 0) {
                dist[ adjoin[now][i] ] = dist[now] + 1;
                myque.push(adjoin[now][i]);
            }
        }
    }
    dist[start] = 0;
}

int main () {
    int n, x, y;
    cin >> n >> x >> y;
    x--, y--;
    if(x == y) {
        cout << 0;
        return 0;
    }
    vector<vector<int>> adjoin(n);
    for (int i = 0; i < n-1; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        adjoin[--temp1].push_back(--temp2);
        adjoin[temp2].push_back(temp1);
    }
    vector<int> distX(n, 0), distY(n, 0);
    myfun(adjoin, x, distX); // X 追 Y，节点都会采取最优路线 记录X到达每个节点的最短路径
    myfun(adjoin, y, distY); // X 追 Y，节点都会采取最优路线 记录Y到达每个节点的最短路径 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // 记录distX[i] 严格大于 distY[i] 的 即 Y先到达 
        // 等于到达的求出来有可能会比ans大（例如同时到A点 然后一起走 走到C点求出结果 不符合 题意）
        // 大于到达的就一定能包含答案
        if(distX[i] > distY[i])
            ans = max(ans, distX[i]);
    }
    cout << ans << endl;
    return 0;
}

// 输入：
// 5 1 2
// 2 1
// 3 1
// 4 2
// 5 3
// 输出：
// 2

// 6 6 5
// 2 1
// 3 1
// 4 2
// 5 3
// 3 6

/* 
题目描述有缺陷，应该加一个小美知道小团每个时刻的位置，并会采取最优移动移向小团，不然最长时间就是无穷大

两人反正是会在某个点相遇的。
树的话，每个节点只有三条路，必然能追上，所以小美必然存在一条最短追杀路线。
从小美的出发点开始DFS，获得小美到所有点的最短路径，答案就在其中。
小团最好的策略显然就是最快的到某个点，然后苟着等着被杀。
所以如果比较所有点，如果小团的最短路径 < 小美的最短路径，那这个点可能就是最优。
链接：https://leetcode-cn.com/problems/vSYUMc/solution/dfs-by-timerizaya-c4f2/
*/