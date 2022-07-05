// https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=295&tqId=654&ru=%2Fpractice%2F75e878df47f24fdc9dc3e400ec6058ca&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

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
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || m==0 || n == 0) return head;
        int index = 0;
		ListNode myhead(-1); myhead.next = head;
		ListNode* now = &myhead, *rhead = nullptr, *temp, *LL, *RR;
		for (int index = 0; index <= n+1; index++) {
			if(index < m) {
				LL = now;
				now = now->next;
			} else if(index <= n) {
				temp = now->next;
				now->next = rhead;
				rhead = now;
				now = temp;
			} else {
				ListNode* RR = LL->next;
				LL->next = rhead;
				RR->next = now;
			}
		}
		return myhead.next;
    }
};