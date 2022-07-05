// https://www.nowcoder.com/practice/f23604257af94d939848729b1a5cda08?tpId=295&tqId=1008897&ru=%2Fpractice%2Fc56f6c70fb3f4849bc56e33ff2a50b6b&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        if(!head || !head->next) 
			return head;
		ListNode* fast = head, *slow = head, h = ListNode(-1), *p = &h; 
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		} // 快慢指针找中点
		fast = slow->next;
		slow->next = nullptr;
		ListNode* l = sortInList(head), *r = sortInList(fast);
		while (l && r) {
			if(l->val <= r->val) {
				p->next = l;
				l = l->next;
			} else {
				p->next = r;
				r = r->next;
			}
			p = p->next;
		}
		p->next = l ? l : r;
		return h.next;
    }
};