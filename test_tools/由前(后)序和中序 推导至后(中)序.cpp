/* 问题描述
　　最近，WYF正准备参观他的点卡工厂。WYF集团的经理氰垃圾需要帮助WYF设计参观路线。现在，氰垃圾知道一下几件事情：
　　1.WYF的点卡工厂构成一颗二叉树。
　　2.一共有n座工厂。
　　3.他需要把这颗树上的点以后序遍历的方法列出来，才能绘制地图。
　　还好，最近他的属下给了他先序遍历和中序遍历的数据。可是，氰垃圾最近还要帮㊎澤穻解决一些问题，没有时间。
    请你帮帮他，替他完成这项任务。由于氰垃圾的一些特殊的要求，WYF的参观路线将会是这棵树的后序遍历。
输入格式
　　第一行一个整数n，表示一共又n座工厂。
　　第二行n个整数，表示先序遍历。
　　第三行n个整数，表示中序遍历。
输出格式
　　输出共一行，包含n个整数，为后序遍历。
样例输入
8
1 2 4 5 7 3 6 8
4 2 7 5 1 8 6 3
样例输出
4 7 5 2 8 6 3 1
数据规模和约定
　　0<n<100000,。保证先序遍历和中序遍历合法，且均为1～n。 */


/*  此题即为由先、中序排列确定 后序排序; 首先要知道一个结论，前序/后序+中序序列可以唯一确定一棵二叉树，所以自然而然可以用来建树。
    看一下前序和中序有什么特点，前序1,2,4,7,3,5,6,8 ，中序4,7,2,1,5,3,8,6；
有如下特征：
    前序中左起第一位1肯定是根结点，我们可以据此找到中序中根结点的位置rootin；（后序中最后一位肯定是根节点。）
    中序中根结点左边就是左子树结点，右边就是右子树结点，即[左子树结点，根结点，右子树结点]，我们就可以得出左子树结点个数为int left = rootin - leftin;；
    前序中结点分布应该是：[根结点，左子树结点，右子树结点]；（后序中分布：[左子树节点, 右子树节点, 根节点]）
    根据前一步确定的左子树个数，可以确定前序中左子树结点和右子树结点的范围；
    如果我们要前序遍历生成二叉树的话，下一层递归应该是：
    左子树：root->left = pre_order; (前序左子树范围，中序左子树范围，前序序列，中序序列)
    右子树：root->right = pre_order; (前序右子树范围，中序右子树范围，前序序列，中序序列)
    每一层递归都要返回当前根结点root； 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return pre_order(0, inorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }
    
    TreeNode *pre_order(int leftpre, int rightpre, int leftin, int rightin, vector<int> &pre, vector<int> &in) {
        if (leftpre > rightpre || leftin > rightin) return NULL;
        TreeNode *root = new TreeNode(pre[leftpre]);
        int rootin = leftin;
        while (rootin <= rightin && in[rootin] != pre[leftpre]) rootin++;
        int left = rootin - leftin;
        root->left = pre_order(leftpre + 1, leftpre + left, leftin, rootin - 1, pre, in);
        root->right = pre_order(leftpre + left + 1, rightpre, rootin + 1, rightin, pre, in);
        return root;
    }
};              */

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    
TreeNode *OrderToTree(int L_Pre, int R_Pre, int L_In, int R_In, vector<int> &Pre, vector<int> &In) 
{   
    if (L_Pre > R_Pre || L_In > R_In)
        return NULL;
    TreeNode *root = new TreeNode(Pre[L_Pre]);   //前序排列中 最左位为根节点
    int in_root = L_In;
    while (In[in_root] != Pre[L_Pre]) {
        in_root++; }
    int left = in_root - L_In;
    root->left = OrderToTree(L_Pre + 1, L_Pre + left, L_In, L_In + left, Pre, In); 
    root->right = OrderToTree(L_Pre + left +1, R_Pre, L_In + left +1, R_In, Pre, In); 
    return root;
}

//打印逆序排序
void PosOrder (TreeNode* root)
{
    if(root == NULL)
        return;
    PosOrder(root->left);
    PosOrder(root->right);
    cout << root->val << ' ';
}


int main ()
{
    int n;  // 0<n<=1000000
    // int PreNumber[100000] = {0}, InNumber[100000] = {0}, PosNumber[100000] = {0};
    vector<int> PreNumber, InNumber, PosNumber;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int j; 
        cin >> j;
        PreNumber.push_back(j);
    }

    for (int i = 0; i < n; i++) {
        int j; 
        cin >> j;
        InNumber.push_back(j);        
    }

    TreeNode *root  = OrderToTree(0, n-1, 0, n-1, PreNumber, InNumber); 
    PosOrder (root);

    return 0;
}