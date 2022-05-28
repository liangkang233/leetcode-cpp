/*
 * @lc app=leetcode.cn id=23 lang=cpp
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
// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
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
// @lc code=end

// 官方答案用的分治法，这就是归并排序算法的思路 居然没想到
class Solution {
public:
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; aPtr = aPtr->next;
            } else {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* merge(vector <ListNode*> &lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};

// 官方的优先队列， 像官方一样加个虚拟头 的确方便些
class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};


// 二刷
class mycmp {
public:
    bool operator() (const ListNode* L, const ListNode* R) {
        return L->val > R->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, mycmp> myque; // 小根堆
        ListNode head = ListNode(-1), *now = &head;
        for (int i = 0; i < lists.size(); i++) {
            if(lists[i])
                myque.push(lists[i]);
        }
        while (!myque.empty()) {
            now->next = myque.top();
            now = now->next;
            myque.pop();
            if(now->next)
                myque.push(now->next);
        }
        return head.next;
    }
};


// 网友提供的堆优先队列，有库实现的用起来真的是方便，比自己实现的不用考虑的内存越界等问题
// 优先队列使用方法： https://blog.csdn.net/xiaoquantouer/article/details/52015928

// 由小到大
priority_queue<int> p;
// p.push(1);
// p.push(2);
// p.push(8);
// p.push(5);
// p.push(43);
// for(int i=0;i<5;i++){
//     cout<<p.top()<<endl;
//     p.pop();
// }
// 输出 43 8 5 2 1

// 由大到小
priority_queue<int, vector<int>, greater<int> > p;

// 重载
struct cmp{
	bool operator()(ListNode a, ListNode b){
		return a.val < b.val;
	}
};
int main(){
	priority_queue<ListNode, vector<ListNode>, cmp> p;


// great定义
// template <class T> struct greater {
//   bool operator() (const T& x, const T& y) const {return x>y;}
//   typedef T first_argument_type;
//   typedef T second_argument_type;
//   typedef bool result_type;
// };