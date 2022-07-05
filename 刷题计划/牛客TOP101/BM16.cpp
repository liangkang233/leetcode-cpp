// https://www.nowcoder.com/practice/71cef9f8b5564579bf7ed93fbe0b2024?tpId=295&tqId=663&ru=%2Fpractice%2Fc087914fae584da886a0091e877f2c79&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

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
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
		ListNode vhead(-1000), *now = head, *last = &vhead;
		last->next = head;
		while (now && now->next) {
			if(now->val == now->next->val) {
				int v = now->val;
				while (now && now->val == v)
					now = now->next;
				last->next = now;
				// last = last->next; // 有这句就无法删除连续的重复数字
			} else {
				last = now;
				now = now->next;
			}
		}
		return vhead.next;
    }
};