/*
 *
 * [23] 合并K个升序链表
 */

//  Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 尝试使用堆排序, 堆性质: 某个结点的值总是不大于或不小于其父结点的值；
    // 注意对一个节点做heapify的时候，必须保证它的所有子树都已经是堆。  
    // 父节点: parent = (i -1)/2        (需保证为完全二叉树)
    // 子节点: son1 = 2*i + 1; son2 = 2*i + 2
    
    vector<ListNode*> heap;
    ListNode* ans = nullptr;
    void heapify(int begin, int end) {
        int parent = begin, son = 2 * begin + 1;
        while (son <= end) {
            if(son+1 <= end && heap[son+1]->val < heap[son]->val)
                son ++;
            if(heap[parent]->val <= heap[son]->val)
                return; //无调整必要
            else {
                swap(heap[parent], heap[son]);
                parent = son;
                son = 2 * son + 1;
            }
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size() - 1;
        // 要小心传入的是空链表，做处理
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == nullptr) {
                k--;
                continue;
            }
            heap.push_back(lists[i]); 
        }
        // 做堆的初始化
        for (int i = (k-1)/2; i >= 0; i--)
            heapify(i, k);

        ListNode *last = nullptr;
        // 将最小值堆顶取出，之后顶部链表节点更新后再heapify
        while (k >= 0) {
            if (ans == nullptr) {
                ans = new ListNode(heap[0]->val);
                last = ans;
            }
            else {
                last->next = new ListNode(heap[0]->val);
                last = last->next;
            }

            if (heap[0]->next != nullptr) {
                heap[0] = heap[0]->next;
                heapify(0, k);                
            }
            else{  //顶部没链表了, 长度减1 heapify
                swap(heap[0], heap[k]);
                --k;
                heapify(0, k);
            }
        }
        return ans;
    }
};

int main () {
    Solution sol;
    ListNode* one = new ListNode(1);
    one->next = new ListNode(2);
    one->next->next = new ListNode(3);
    ListNode* two = nullptr;
    ListNode* there = new ListNode(5);
    there->next = new ListNode(10);
    there->next->next = new ListNode(11);
    ListNode* four = nullptr;

    vector <ListNode*> lists (4, nullptr);
    lists[0] = one;
    lists[1] = two;
    lists[2] = there;
    lists[3] = four;

    ListNode *ans = sol.mergeKLists(lists);
    while (ans!=nullptr) {
        cout << ans->val;
        ans = ans->next;
    }
    
    return 0;
}