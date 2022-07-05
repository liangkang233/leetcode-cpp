// https://www.nowcoder.com/practice/5e2135f4d2b14eb8a5b06fab4c938635?tpId=295&tqId=2291302&ru=%2Fpractice%2F2b317e02f14247a49ffdbdba315459e7&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

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
            ans.push_back(root->val);
            mydfs(root->left);
            mydfs(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        mydfs(root);
        return ans;
    }
};