// https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
	struct TreeNode *left;
	struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> ans;
        stack<TreeNode*> st, st_t;
        if(pRoot) st.push(pRoot);
        bool flag = false;
        while (!st.empty()) {
            vector<int> temp;
            while (!st.empty()) {
                TreeNode* t = st.top(), *l = t->left, *r = t->right;
                st.pop();
                temp.push_back(t->val);
                if(flag) swap(l, r);
                if(l) st_t.push(l);
                if(r) st_t.push(r);
            }
            flag = !flag;
            ans.push_back(temp);
            swap(st, st_t);
        }
        return ans;
    }
};