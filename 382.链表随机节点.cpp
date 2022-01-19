/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 */

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
// 水塘抽样 空间复杂度O(1)
class Solution {
public:
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
    }
    int getRandom() {
        int count = 1, ans = 0;
        for (ListNode* temp=head; temp!=nullptr; temp=temp->next, count++) {
            if(rand()%count == 0)
                ans = temp->val;
        }
        return ans;
    }
};
// @lc code=end
/*
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// ["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]\n[[[10,1,10,20,100]], [], [], [], [], [], [], [], [], [], []]\n


// 普通做法 空间复杂度O(n)
class Solution1 {
public:
    vector<int> ans;
    Solution1(ListNode* head) {
        for (; head!=nullptr; head=head->next)
            ans.push_back(head->val);
    }
    int getRandom() {
        // srand(unsigned (time(NULL)));
        return ans[rand() % ans.size()];
    }
};
// 类似 ../382.链表随机节点.cpp 的题目时不要注入srand((unsigned int)time(NULL))
// 由于测试系统时间是固定的，导致每次rand返回的都是 同一时间种子的 rand序列第一个 所以使用上式后一直是同一个值
// 测试系统是一次性调用n次程序(n较小) 所以无需注入新种子 随机值也算可靠