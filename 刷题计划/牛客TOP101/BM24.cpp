// https://www.nowcoder.com/practice/0bf071c135e64ee2a027783b80bf781d?tpId=295&tqId=1512964&ru=%2Fpractice%2F5e2135f4d2b14eb8a5b06fab4c938635&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

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
    vector<int> ans;
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return int整型vector
     */
    void mydfs(TreeNode* root) {
        if(root) {
            mydfs(root->left);
            ans.push_back(root->val);
            mydfs(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        mydfs(root);
        return ans;
    }
};