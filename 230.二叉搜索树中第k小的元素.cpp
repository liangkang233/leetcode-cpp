/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start

// 如果只查一次 最快就是中序遍历
class Solution {
public:
    int ranking = 0;
    int mydfs(TreeNode* root, int k) {
        if(root->left) {
            int temp = mydfs(root->left, k);
            if(temp >= 0) return temp;
        }
        if(++ranking == k)
            return root->val;
        if(root->right) {
            int temp = mydfs(root->right, k);
            if(temp >= 0) return temp;
        }
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
        return mydfs(root, k);
    }
};
// @lc code=end
// [7,5,10,2,6,null,null,1,4,null,null,null,null,3]\n5
// [5,3,6,2,4,null,null,1]\n3

// 官方中序的栈迭代法
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> stack;
        while (root != nullptr || stack.size() > 0) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            --k;
            if (k == 0) {
                break;
            }
            root = root->right;
        }
        return root->val;
    }


// 频繁查询 第k个的值 记录节点个数
class Solution {
public:
    unordered_map<int, int> mymap; // key 为排名 value为其值
    int mydfs(TreeNode* root, int ranking) {
        int Lval = ranking;
        if(root->left)
            Lval = mydfs(root->left, Lval);
        mymap.insert(make_pair(Lval + 1, root->val));
        int Rval = Lval+1;
        if(root->right)
            Rval = mydfs(root->right, Rval);
        return Rval;
    }
    int kthSmallest(TreeNode* root, int k) {
        mydfs(root, 0);  
        if(mymap.find(k) != mymap.end())
            return mymap[k];
        return -1;
    }
};


// 法三: 如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？
// 需要 使用 平衡树  题解手写的也太狠了 https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/solution/er-cha-sou-suo-shu-zhong-di-kxiao-de-yua-8o07/