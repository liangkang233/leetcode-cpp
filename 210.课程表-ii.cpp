/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


/* 经典的「拓扑排序」问题。
dfs 做法
假设我们当前搜索到了节点 u，如果它的所有相邻节点都已经搜索完成，
那么这些节点都已经在栈中了，此时我们就可以把 u 入栈。可以发现，
如果我们从栈顶往栈底的顺序看，由于 u 处于栈顶的位置，
那么 u 出现在所有 u 的相邻节点的前面。因此对于 u 这个节点而言，
它是满足拓扑排序的要求的。
这样以来，我们对图进行一遍深度优先搜索。当每个节点进行回溯的时候，
我们把该节点放入栈中。最终从栈顶到栈底的序列就是一种拓扑排序。 

对于图中的任意一个节点，它在搜索的过程中有三种状态，即：
「未搜索」：我们还没有搜索到这个节点；
「搜索中」：我们搜索过这个节点，但还没有回溯到该节点，即该节点还没有入栈，还有相邻的节点没有搜索完成）；
「已完成」：我们搜索过并且回溯过这个节点，即该节点已经入栈，并且所有该节点的相邻节点都出现在栈的更底部的位置，满足拓扑排序的要求。
*/

// @lc code=start   
class Solution {
public:
    bool mydfs(vector<int>& record, const vector<vector<int>>& edges, vector<int>& ans, int i) {
        if(record[i] == 1)  return false; // 出现环
        if(record[i] == 0) { // 未搜索 进行遍历
            record[i] = 1;
            for (int j = 0; j < edges[i].size(); j++) {
                if(!mydfs(record, edges, ans, edges[i][j]))
                    return false;
            }
            record[i] = 2;
            ans.push_back(i);
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans, record(numCourses, 0);
        vector<vector<int>> edges(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        for (int i = 0; i < numCourses; i++) {
            if(record[i]==0 && !mydfs(record, edges, ans, i))
                return vector<int>{};
        }
        reverse(ans.begin(), ans.end());
        // 一定要反正push 最后 reverse  否则会出现 例如 4->5->1->2->3 
        // 先排 1 2 3 之后排 4 5 时就会导致反了一部分 如果 在递归后添加元素 则 为 3 2 1 再后面 添加 5 4 翻转后为 45123 正确 
        return ans;
    }
};
// @lc code=end

