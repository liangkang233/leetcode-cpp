/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// @lc code=start
class Solution {
public:
    // bfs 使用队列
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) {
            return  vector<vector<int>>{};
        }
        vector<vector<int>> ans{vector<int>{}};
        queue<Node*> myqueue;
        myqueue.push(root);
        int i = 0, temp1 = 1, temp2 = 0; //i记录是第几行扫描，
        // temp1记录这次还要扫描几个节点 temp2记录下一次还要扫描几个节点
        while(!myqueue.empty()) {
            root = myqueue.front();
            myqueue.pop();
            for (int j = 0; j < root->children.size(); j++) {
                temp2++;
                myqueue.push(root->children[j]);
            }
            temp1--;
            ans[i].push_back(root->val);
            if (temp1 == 0) {
                if (temp2 == 0)// 已经扫描到最后一行，不需要新增一行
                    continue;
                ans.push_back(vector<int>{});
                temp1 = temp2, temp2 = 0, i++;
            }
        }
        return ans;
    }
};
// @lc code=end

