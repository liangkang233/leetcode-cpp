/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 常规方法用字段/前缀树 看官方的即可
// 为了后面累加计算 倒着计算每个数的二进制 最大31位
// @lc code=start
struct trieNode {
    vector<trieNode*> son;
    trieNode(): son(2) {}
};
class Solution {
public:
    void add(trieNode* root, int val) {
        trieNode* now = root;
        for (int i = 30; i >= 0; i--) {
            int s = val >> i & 1;
            if(!now->son[s])
                now->son[s] = new trieNode();
            now = now->son[s];
        }
    }
    int search(trieNode* root, int val) {
        trieNode* now = root;
        int temp = 0;
        for (int i = 30; i >= 0; i--) {
            int s = (val >> i & 1) == 1 ? 0 : 1; // 找异或的数位 即相反的方向
            temp = 2*temp+1;
            // 该数位数字不存在 转为跟树相同方向 该子树一定存在!! 
            // 因为是反向填入数据 每个节点的深度都为31
            if(!now->son[s]) {
                s = s == 1 ? 0 : 1; 
                temp--;
            }
            now = now->son[s];
        }
        return temp;
    }
    // 为了加速 删除了析构部分
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        trieNode* root = new trieNode();
        for (int i = 1; i < nums.size(); i++) {
            add(root, nums[i-1]);
            ans = max(ans, search(root, nums[i]));
        }
        return ans;
    }
};
// @lc code=end


// 为了后面累加计算 倒着计算每个数的二进制 最大31位
// 在计算异或结果最大值 ans 的前 ii位 时
// 如果 a ^ b = c 成立，那么 a ^ c = b 与 b ^ c = a 均成立。
// 遍历到 第ii位时 当前最大值应该为 2*ans + 1
// 所以 若存在 num1 ^ num2 == ans 则 ans ^ numi 应该能在 set 中查询到
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        for (int ii = 30; ii >= 0; ii--) {
            unordered_set<int> myset;
            for (int i = 0; i < nums.size(); i++)
                myset.insert(nums[i] >> ii);
            ans = 2*ans + 1; // 先假设能找到匹配值 使得该位加1
            bool flag = false;
            for (int i = 0; i < nums.size(); i++) {
                if(myset.find(nums[i] >> ii ^ ans) != myset.end()) {
                    flag = true;
                    break;
                }
            }
            if(!flag) ans--;
        }
        return ans;
    }
};