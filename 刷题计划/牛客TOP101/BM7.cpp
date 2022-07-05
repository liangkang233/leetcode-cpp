// https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=295&tqId=23449&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* fast = pHead, *slow = pHead;
		while (fast) {
			slow = slow->next;
			fast = fast->next;
			if(fast) 
				fast = fast->next;
			else
				break;
			if(fast == slow) {
				slow = pHead;
				while (slow != fast) {
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
		}
		return nullptr;
    }
};