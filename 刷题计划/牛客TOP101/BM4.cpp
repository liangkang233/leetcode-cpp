// https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=295&tqId=23267&ru=%2Fpractice%2Fb49c3dc907814e9bbfa8437c251b028e&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode head(-1), *phead = &head;
		while (pHead1 && pHead2) {
			if(pHead1->val <= pHead2->val) {
				phead->next = pHead1;
                pHead1 = pHead1->next;
            } else {
				phead->next = pHead2;
                pHead2 = pHead2->next;

            }
			phead = phead->next;
		}
		phead->next = pHead1 ? pHead1 : pHead2;
		return head.next;
    }
};