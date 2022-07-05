// https://www.nowcoder.com/practice/c56f6c70fb3f4849bc56e33ff2a50b6b?tpId=295&tqId=1008772&ru=%2Fpractice%2F6ab1d9a29e88450685099d45c9e31e46&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

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
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
	ListNode* reverse(ListNode* head) {
		ListNode* rhead = nullptr, *temp;
		while (head) {
			temp = head->next;
			head->next = rhead;
			rhead = head;
			head = temp;
		}
		return rhead;
	}
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        if(!head1 || !head2)
			return head1 ? head1 : head2;
		int k = 0;
		ListNode* rh1 = reverse(head1), *rh2 = reverse(head2), h(-1), *ph = &h;
		while (rh1 || rh2 || k > 0) {
			int l1 = 0, l2 = 0;
			if(rh1) {
				l1 = rh1->val;
				rh1 = rh1->next;
			}
			if(rh2) {
				l2 = rh2->val;
				rh2 = rh2->next;
			}
			ph->next = new ListNode((l1 + l2 + k) % 10);
			ph = ph->next;
			k = (l1 + l2 + k) / 10;
		}
		return reverse(h.next);
    }
};