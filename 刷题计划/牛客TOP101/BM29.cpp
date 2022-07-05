// https://www.nowcoder.com/practice/508378c0823c423baa723ce448cbfd0c?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
	struct TreeNode *left;
	struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 牛客的案例也太恶心了 root 为空 sum为0 返回false
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    bool mydfs(TreeNode* root, int sum) {
        sum -= root->val;
        if(!root->left && !root->right) {
            cout << sum << endl;
            return sum == 0;
        }
        if(root->left && mydfs(root->left, sum)) 
            return true;
        if(root->right && mydfs(root->right, sum)) 
            return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) 
            return false;
        return mydfs(root, sum);
    }
};