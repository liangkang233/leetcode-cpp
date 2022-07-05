// https://www.nowcoder.com/practice/3fed228444e740c8be66232ce8b87c2f?tpId=295&tqId=1008769&ru=%2Fpractice%2Ff23604257af94d939848729b1a5cda08&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
	ListNode* reverse(ListNode* head) {
		ListNode* temp, *rhead = nullptr;
		while (head) {
			temp = head->next;
			head->next = rhead;
			rhead = head;
			head = temp;
		}
		return rhead;
	}
    bool isPail(ListNode* head) {
		if(!head) return true;
        ListNode *fast = head, *slow = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow->next;
		slow->next = nullptr;
		fast = reverse(fast);
		slow = head;
		while (fast && slow) {
			if(fast->val != slow->val)
				return false;
			fast = fast->next;
			slow = slow->next;
		}
		return true;
    }
};   