/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
// 暴力dfs
class Solution {
public:
    bool mydfs (TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot)
            return !root && !subRoot;
        if(root->val == subRoot->val && mydfs(root->left, subRoot->left) && mydfs(root->right, subRoot->right))
            return true;
        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot)
            return !root && !subRoot;
        if(mydfs(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
// @lc code=end
// [3,4,5,1,2,null,null,null,null,0]\n[4,1,2]\n

// 前序数组对比 效果一般 甚至不如dfs
// 这样做正确吗?假设8由两个点组成，1 是根，2是1的左孩子; t也由两个点组成，1是根，2是1的右孩
// 子。这样一来s和t的深度优先搜索序列相同，可是t并不是8的某一 棵子树。由此可见「s的深度优先搜
// 索序列包含t的深度优先搜索序列」是「t是s子树」的必要不充分条件，所以单纯这样做是不正确的。

// 所以需要在终止节点添加特殊值，否则不一定正确，之后再用kmp对比即可
// 这里直接假设特殊值为 INT_MAX-1 与 INT_MAX-2
#define Lend  INT_MAX-1
#define Rend  INT_MAX-2

class Solution {
public:
    bool PreDfs(TreeNode* root, vector<int>& array) {
        if(root) {
            array.push_back(root->val);
            if(!PreDfs(root->left, array))
                array.push_back(Lend);
            if(!PreDfs(root->right, array))
                array.push_back(Rend);
            return true;
        }
        else
            return false;
    }
    bool kmp(vector<int>& array1, vector<int>& array2) {
        vector<int> next(array2.size(), -1);
        for (int j=1, i=-1; j < array2.size(); j++) {
            while (i!=-1 && array2[j] != array2[i+1])
                i = next[i];
            if(array2[j] == array2[i+1])
                i++;
            next[j] = i;
        }
        for (int j=0, i=-1; j < array1.size(); j++) {
            while (i!=-1 && array1[j] != array2[i+1])
                i = next[i];
            if(array1[j] == array2[i+1])
                i++;
            if(i == array2.size() - 1)
                return true;
        }
        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root || !subRoot)
            return !root && !subRoot;
        vector<int> array1, array2;
        PreDfs(root, array1);
        PreDfs(subRoot, array2);
        return kmp(array1, array2); //查询subroot的补齐节点后 前序数组 是否存在 root数组中
    }
};


// 哈希做法 ACM题
// https://leetcode-cn.com/problems/subtree-of-another-tree/solution/ling-yi-ge-shu-de-zi-shu-by-leetcode-solution/
class Solution {
public:
    static constexpr int MAX_N = 1000 + 5;
    static constexpr int MOD = int(1E9) + 7;

    bool vis[MAX_N];
    int p[MAX_N], tot;
    void getPrime() {
        vis[0] = vis[1] = 1; tot = 0;
        for (int i = 2; i < MAX_N; ++i) {
            if (!vis[i]) p[++tot] = i;
            for (int j = 1; j <= tot && i * p[j] < MAX_N; ++j) {
                vis[i * p[j]] = 1;
                if (i % p[j] == 0) break;
            }
        }
    }

    struct Status {
        int f, s; // f 为哈希值 | s 为子树大小
        Status(int f_ = 0, int s_ = 0) 
            : f(f_), s(s_) {}
    };

    unordered_map <TreeNode *, Status> hS, hT;

    void dfs(TreeNode *o, unordered_map <TreeNode *, Status> &h) {
        h[o] = Status(o->val, 1);
        if (!o->left && !o->right) return;
        if (o->left) {
            dfs(o->left, h);
            h[o].s += h[o->left].s;
            h[o].f = (h[o].f + (31LL * h[o->left].f * p[h[o->left].s]) % MOD) % MOD;
        }
        if (o->right) {
            dfs(o->right, h);
            h[o].s += h[o->right].s;
            h[o].f = (h[o].f + (179LL * h[o->right].f * p[h[o->right].s]) % MOD) % MOD;
        }
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        getPrime();
        dfs(s, hS);
        dfs(t, hT);

        int tHash = hT[t].f;
        for (const auto &[k, v]: hS) {
            if (v.f == tHash) {
                return true;
            }
        } 

        return false;
    }
};