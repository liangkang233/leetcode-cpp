/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// @lc code=start

// 二叉树的  序列 反序列化 做树最常见的模块了

// 使用层序遍历进行序列反序列化
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "[]";
        string ans = "[";
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* now = que.front();
            que.pop();
            if(now) {
                ans += to_string(now->val) + ',';
                que.push(now->left);
                que.push(now->right);
            }
            else
                ans += "null,";
        }
        ans.back() = ']';
        // cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]") return nullptr;
        vector<int> record;
        int i = 1, j = 1;
        for (i = 1, j = 1; i < data.size(); i++) {
            if(data[i] == ',') {
                string temp = data.substr(j, i-j);
                // cout << temp << endl;
                if(temp == "null")
                    record.push_back(INT_MIN);
                else 
                    record.push_back(stoi(temp));
                j = i+1;
            }
        }
        string temp = data.substr(j, i-j-1);
        // cout << temp << endl;
        if(temp == "null")
            record.push_back(INT_MIN);
        else 
            record.push_back(stoi(temp));

        TreeNode* head = new TreeNode(record[0], nullptr, nullptr);
        queue<TreeNode*> que, que1; // que 为当前队列 que1为当前队列
        que.push(head);
        i = 1;
        while(!que.empty() || !que1.empty()) {
            if(que.empty())
                swap(que, que1);
            TreeNode* Now = que.front();
            que.pop();
            if(i < record.size() && record[i] != INT_MIN) {
                Now->left = new TreeNode(record[i], nullptr, nullptr);
                que1.push(Now->left);
            }
            i++;
            if(i < record.size() && record[i] != INT_MIN) {
                Now->right = new TreeNode(record[i], nullptr, nullptr);
                que1.push(Now->right);
            }
            i++;
        }
        return head;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
// [7,5,10,2,6,null,null,1,4,null,null,null,null,3]\n
// [5,3,6,2,4,null,null,1]\n

// 官方答案 dfs
class Codec {
public:
    void rserialize(TreeNode* root, string& str) {
        if (root == nullptr) {
            str += "None,";
        } else {
            str += to_string(root->val) + ",";
            rserialize(root->left, str);
            rserialize(root->right, str);
        }
    }

    string serialize(TreeNode* root) {
        string ret;
        rserialize(root, ret);
        return ret;
    }

    TreeNode* rdeserialize(list<string>& dataArray) {
        if (dataArray.front() == "None") {
            dataArray.erase(dataArray.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(dataArray.front()));
        dataArray.erase(dataArray.begin());
        root->left = rdeserialize(dataArray);
        root->right = rdeserialize(dataArray);
        return root;
    }

    TreeNode* deserialize(string data) {
        list<string> dataArray;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                dataArray.push_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            dataArray.push_back(str);
            str.clear();
        }
        return rdeserialize(dataArray);
    }
};


// 妙啊 简洁
class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

// 二刷
class Codec {
public:
    void mydfs(TreeNode* root, string& data) {
        if(!root)
            data += "# ";
        else {
            data += to_string(root->val);
            data.push_back(' ');
            mydfs(root->left, data);
            mydfs(root->right, data);
        }
    }
    TreeNode* mydfs1(istringstream& it) {
        string temp;
        TreeNode* node = nullptr;
        it >> temp;
        if(temp != "#")
            node = new TreeNode(stoi(temp), mydfs1(it), mydfs1(it));
        return node;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        mydfs(root, data);
        // cout << data;
        return data;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        istringstream it(data);
        return mydfs1(it);
    }
};
