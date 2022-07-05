// https://www.nowcoder.com/practice/b49c3dc907814e9bbfa8437c251b028e?tpId=295&tqId=722&ru=%2Fpractice%2Fb58434e200a648c589ca2063f1faf58c&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

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
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n, size = 0;
		ListNode myhead(-1); myhead.next = head;
		ListNode* t = head, *rhead, *temp, *LL = &myhead, *RR = &myhead;
		while (t) {
			size++;
			t = t->next;
		} n = size / k;
		t = head;
		for (int i = 0; i < n; i++) {
			LL = RR;
			for (int j = 0; j < k; j++) {
				temp = t->next;
				t->next = rhead;
				rhead = t;
				t = temp;
			}
			RR = LL->next;
			LL->next = rhead;
			RR->next = t;
		}
		return myhead.next;
    }
}; 