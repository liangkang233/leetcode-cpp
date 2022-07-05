// https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
	struct TreeNode *left;
	struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void mydfs(TreeNode *root, string& s) {
        if(!root) s+= "# ";
        else {
            s += to_string(root->val) + " ";
            mydfs(root->left, s);
            mydfs(root->right, s);
        }
    }
    TreeNode* mydfs1(istringstream& in) {
        string temp;
        in >> temp;
        if(temp == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(temp));
        root->left = mydfs1(in);
        root->right = mydfs1(in);
        return root;
    }
    char* Serialize(TreeNode *root) {    
        string s;
        mydfs(root, s);
        char* arr = new char[s.size()];
        strcpy(arr, s.c_str());
        // cout << s << endl;
        return arr;
    }
    TreeNode* Deserialize(char *str) {
        string s(str);
        istringstream in(s);
        return mydfs1(in);
    }
};