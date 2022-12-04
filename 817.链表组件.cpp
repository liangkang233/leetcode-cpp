/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
 */


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        // auto myfun = [](int n) {return n*(n+1)/2;}; // 想多了 以为是求子集 只要最长的加一即可
        int ans = 0, index = 0, last = 0;
        bool have = false;
        unordered_set<int> ms;
        for(int i : nums) ms.insert(i);
        ListNode* now = head;
        while (now) {
            while (now && ms.find(now->val) == ms.end()) {
                index++;
                now = now -> next;
            }
            last = index;
            while (now && ms.find(now->val) != ms.end()) {
                index++;
                now = now -> next;
                have = true;
            }
            if(have) {
                // cout << last << " " << index << " " << " 连续" index - last << "个" << endl;
                // ans += myfun(index - last);
                ans++;
                have = false;
            }
        }
        if(have) {
            ans++;
            // cout << last << " " << index << " " << " 连续" index - last << "个" << endl;
            // ans += myfun(index - last);
        }
        return ans;
    }
};
// @lc code=end

// 看看官解 简洁优雅
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> numsSet;
        for (int num : nums) {
            numsSet.emplace(num);
        }
        bool inSet = false;
        int res = 0;
        while (head != nullptr) {
            if (numsSet.count(head->val)) {
                if (!inSet) {
                    inSet = true;
                    res++;
                }
            } else {
                inSet = false;
            }
            head = head->next;
        }
        return res;
    }
};