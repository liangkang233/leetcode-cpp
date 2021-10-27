
#include <iostream>
#include <queue>
#include <vector>
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
class Solution {
public:
    // 递归 dfs
    bool dfs(TreeNode* temp, int lower, int upper) {
        if(temp->left) {
            TreeNode* tempL = temp->left;
            if(tempL->val >= upper)
                return false;
            if (!dfs(tempL, lower, tempL->val))
                return false;            
        }
        if (temp->right) {
            TreeNode* tempR = temp->right;
            if(tempR->val <= lower)
                return false;
            if (!dfs(tempR, tempR->val, upper))
                return false;      
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        if (!root) 
            return false;
        return dfs(root, root->val, root->val);
    }
};

class Solution1 {
public:
    vector<vector <int>> ans;
    queue<TreeNode *> myque;

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) 
            return ans;
        myque.push(root);

        while ( !myque.empty()) {
            ans.push_back(vector<int> ());
            int N = myque.size(), num = ans.size();
            
            for (int i = 0; i < N; i++) {
                TreeNode* temp = myque.front();
                myque.pop();
                ans[num-1].push_back(temp->val);
                if(temp->left != nullptr)
                    myque.push(temp->left);
                if(temp->right != nullptr)
                    myque.push(temp->right);
            }
        }
        return ans;
    }
};

int main () {
    Solution Sol;
    Solution1 Sol1;
    TreeNode i(4);
    TreeNode i1(3);
    TreeNode i2(7);
    TreeNode j(6, &i1, &i2);
    TreeNode root(5, &i, &j);

    cout << "test1" << Sol.isValidBST(&root) << endl;
    vector<vector <int>> ans = Sol1.levelOrder(&root);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}


