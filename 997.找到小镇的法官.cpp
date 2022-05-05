/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1)
            return trust.empty() ? 1 : -1;
        vector<bool> tr(n+1, false); // true表示 那些人不能当法官 即相信别人
        vector<int> record(n+1, 0); // 被人相信的次数
        int people = -1;
        for (int i = 0; i < trust.size(); i++) {
            int x = trust[i][0], y = trust[i][1];
            if(x == people) // 法官不相信任何人
                return -1;
            tr[x] = true;
            if(++record[y] == n-1) { // 法官不相信任何人 被n-1人相信只能是法官)
                if(people > 0 || tr[y]) // 存在多个法官 或者此人相信别人 法官不相信任何人
                    return -1;
                people = y;
            }
        }
        return people;
    }
};
// @lc code=end
// 3\n[[1,3],[2,3]]
// 3\n[[1,3],[2,3],[3,1]]
// 1\n[]

// 用图论的知识解答
// trust 的元素 trust[i] 是图的有向边，从 trust[i][0] 指向 trust[i][1]
// 我们可以遍历 trust，统计每个节点的入度和出度，存储在 inDegrees 和 outDegrees
// 根据题意，在法官存在的情况下，法官不相信任何人，每个人（除了法官外）都信任法官，
// 且只有一名法官。因此法官这个节点的入度是 n-1, 出度是 0。
// 我们可以遍历每个节点的入度和出度，如果找到一个符合条件的节点，
// 由于题目保证只有一个法官，我们可以直接返回结果；如果不存在符合条件的点，则返回 -1。
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegrees(n + 1);
        vector<int> outDegrees(n + 1);
        for (auto& edge : trust) {
            int x = edge[0], y = edge[1];
            ++inDegrees[y];
            ++outDegrees[x];
        }
        for (int i = 1; i <= n; ++i) {
            if (inDegrees[i] == n - 1 && outDegrees[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};