// https://www.nowcoder.com/practice/8daa4dff9e36409abba2adbe413d6fae?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
	struct TreeNode *left;
	struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @return bool布尔型
     */
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        if(root) que.push(root);
        bool flag = false;
        int N = 1;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* front = que.front();
                que.pop();
                if(flag && front->left) {
                    return false;
                }
                else if(front->left) 
                    que.push(front->left);
                else
                    flag = true; 
                if(flag && front->right) {
                    return false;
                }
                else if(front->right) 
                    que.push(front->right);
                else
                    flag = true;
            }
            if(flag && size != N && !que.empty()) {
                return false;
            }
            N = 2 * N;
        }
        return true;
    }
};


// 写的一坨shit 看看官解吧家人们
class Solution {
  public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) 
            return true;
        queue<TreeNode*> q;
        q.push(root); 
        bool flag = false;  //定义一个首次出现的标记位
        while(!q.empty()){ 
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur == NULL) //标记第一次遇到空节点
                    flag = true; 
                else{ //后续访问已经遇到空节点了，说明经过了叶子
                    if (flag) return false;
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        return true;
    }
};
