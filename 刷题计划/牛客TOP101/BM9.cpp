// https://www.nowcoder.com/practice/f95dcdafbde44b22a6d741baf71653f6?tpId=295&tqId=727&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

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
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode myhead(-1); myhead.next = head;
		ListNode *now = &myhead, *tail = now;
        for (int i = 0; i <= n; i++)
            tail = tail->next;
        while (tail) {
            tail = tail -> next;
            now = now -> next;
        } // now为倒数n+1个
        now->next = now->next->next;
        return myhead.next;
    }
};