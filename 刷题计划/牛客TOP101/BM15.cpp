// https://www.nowcoder.com/practice/c087914fae584da886a0091e877f2c79?tpId=295&tqId=664&ru=%2Fpractice%2F02bf49ea45cd486daa031614f9bd6fc3&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

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
		int v = -1001;
		ListNode* now = head, *last = nullptr;
		while (now) {
			if(now->val == v) {
				last->next = now->next;
			} else {
				last = now;
                v = now->val;
			}
			now = now->next;
		}
		return head;
    }
};