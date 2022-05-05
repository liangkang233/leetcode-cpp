/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 此题即为560题的升级

// @lc code=start
class Solution {
private:
    int target, ans = 0;
public:
    // 试试 先序遍历 直接穷举所有路径
    void mydfs(TreeNode* root, vector<long long>& record) {
        if(root) {
            record.push_back(0);
            for (int i = 0; i < record.size(); i++) {
                record[i] += root->val;
                if(record[i] == target)
                    ans++;
            }
            mydfs(root->left, record);
            mydfs(root->right, record);
            for (int i = 0; i < record.size(); i++)
                record[i] -= root->val;
            record.pop_back();
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<long long> record;
        target = targetSum;
        mydfs(root, record);
        return ans;
    }
};
// @lc code=end
// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22
// []\n22
// [1]\n1


// 官方 用map优化 记录前缀和解个数
class Solution {
public:
    unordered_map<long long, int> prefix;
    int dfs(TreeNode *root, long long curr, int targetSum) {
        if (!root) {
            return 0;
        }

        int ret = 0;
        curr += root->val;
        if (prefix.count(curr - targetSum)) {
            ret = prefix[curr - targetSum];
        }

        prefix[curr]++;
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix[curr]--;

        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};

class Solution {
private:
    unordered_map<long long, int> record;
    int target, ans = 0;
public:
    // map 记录前缀和
    void mydfs(TreeNode* root, long long& now) {
        if(root) {
            now += root->val;
            ans += record[now-target]; // 顺序不能变 一定先查询 后添加对应前缀和
            record[now]++;
            mydfs(root->left, now);
            mydfs(root->right, now);
            record[now]--;
            now -= root->val;
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        record[0] = 1;
        long long now = 0;
        mydfs(root, now);
        return ans;
    }
};