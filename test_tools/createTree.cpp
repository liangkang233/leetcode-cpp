#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define mynull -1000

// 用于测试的辅助构建树函数

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 视作完全二叉树的输入 dfs遍历子节点(2i+1 2i+2) 或者bfs子节点 (要处理空节点 比较麻烦)
TreeNode* createTree(vector<int>& tree, int i) {
    TreeNode* root = nullptr;
    if(i < tree.size() && tree[i] != mynull)
        root = new TreeNode(tree[i], createTree(tree, 2*i+1), createTree(tree, 2*i+2));
    return root;
}

void PreOrder(TreeNode* head); // 先序遍历
void LevelOrder(TreeNode* head); // 层次遍历

int main () {
    vector<int> tree1{3,4,5,1,2,mynull,mynull,mynull,mynull,0};
    vector<int> tree2{4,1,2};
    auto root1 = createTree(tree1, 0);
    auto root2 = createTree(tree2, 0);
    LevelOrder(root1);
    cout << endl;
    LevelOrder(root2);
    cout << endl;
    return 0;
}

void PreOrder(TreeNode* head)
{
    if (head == nullptr)
        return;
    cout << head->val << " ";
    PreOrder(head->left);
    PreOrder(head->right);
}

void LevelOrder(TreeNode* head)
{
    if (head) {
        queue<TreeNode*> queue;
        queue.push(head);
        TreeNode* cur;
        while (!queue.empty()) {
            cur = queue.front();
            queue.pop();
            cout << cur->val << " ";
            if (cur->left)
                queue.push(cur->left);
            if (cur->right)
                queue.push(cur->right);
        }
    }
}