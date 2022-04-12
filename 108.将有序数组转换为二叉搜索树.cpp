/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* mydfs(vector<int>& nums, int begin, int end) {
    TreeNode* left = nullptr, *right = nullptr;
    // int mid = (begin + end) / 2;
    int mid = (begin + end + 1) / 2;
    if(mid-1 >= begin)
        left = mydfs(nums, begin, mid-1);
    if(end >= mid+1)
        right = mydfs(nums, mid+1, end); 
    TreeNode* root = new TreeNode(nums[mid], left, right);
    return root;
}


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* head = mydfs(nums, 0, nums.size()-1);
        return head;
    }
};

// 求mid使用 (start + end+1)/2 就是官方答案那样输出 优先填充左树
// @lc code=end