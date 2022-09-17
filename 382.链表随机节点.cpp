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


// P(第i个节点的值成为最后被返回的值)
// =P(第i次随机选择的值=0)x P(第i+ 1次随机选择的值≠0)x .... x P(第n次随机选择的值≠0)
// =1/i * (1 - 1/(i+1)) * (1 - 1/(i+2)) * .... * (1-1/n)
// =1/n


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
// 由于测试系统时间是固定的，导致每次rand返回的都是 同一时间种子的 rand序列第一个 
// 所以使用上式后 每次程序执行案例 一直是同一个值序列的前几个值
// 而用 rand 是同一序列的遍历值。
// 测试系统是一次性调用n次程序(n较小) 所以无需注入新种子 随机值也算可靠



/* 
链接：https://www.nowcoder.com/questionTerminal/12796031452e4ced8a16255bb02c4168
m 个 取 n 个的水塘抽样

整数数组的前m个直接存下来。
用一个计数器保存当前正在处理的请求是第几个，比如n
对于从m+1开始的新请求，以m/n的概率选择保存，并同从已保存的m个请求中随机选出的一个进行交换。
细说就是，

对于第m+1个请求，以m/(m+1)的概率选择留下，如果留下了则从已保存的m个请求中随机选出一个，同它交换;
对于第m+2个请求，以m/(m+2)的概率选择留下，如果留下了则从已保存的m个请求中随机选出一个，同它交换;
对于第m+3个请求，以m/(m+3)的概率选择留下，如果留下了则从已保存的m个请求中随机选出一个，同它交换;
。。。
对于第n个请求，以m/n的概率选择留下，如果留下了则从已保存的m个请求中随机选出一个，同它交换 */