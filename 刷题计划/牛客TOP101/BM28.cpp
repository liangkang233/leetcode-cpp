// https://www.nowcoder.com/practice/8a2b2bf6c19b4f23a9bdb9b233eefa73?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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

class Solution {
private:
    int maxn = 0;
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    void mydfs(TreeNode* root, int depth) {
        if(root) {
            maxn = max(maxn, depth);
            mydfs(root->left, depth+1);
            mydfs(root->right, depth+1);
        }
    }
    int maxDepth(TreeNode* root) {
        mydfs(root, 1);
        return maxn;
    }
};