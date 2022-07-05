// https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6?tpId=295&tqId=724&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode * merge(vector<ListNode *> &lists, int l, int r) {
		if(l > r)	return nullptr;
		if(l == r)	return lists[l];
		int mid = (l + r) / 2;
		ListNode* LL = merge(lists, l, mid);
		ListNode* RR = merge(lists, mid+1, r);
		ListNode ans(-1), *now = &ans;
		while (LL && RR) {
			if(LL->val <= RR->val) {
				now->next = LL;
				LL = LL->next;
			} else {
				now->next = RR;
				RR = RR->next;				
			}
			now = now->next;
		}
		now->next = LL ? LL : RR;
		return ans.next;
	}
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		return merge(lists, 0, lists.size()-1);
    }
};