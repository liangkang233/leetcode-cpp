// https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=295&tqId=23257&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		if(!pHead1 || !pHead2) 
            return nullptr;
        ListNode* node1 = pHead1, *node2 = pHead2;
		while (node1 != node2) {
			node1 = node1->next;
			node2 = node2->next;
            if(!node1 && !node2) 
				break; // 无交点
			else if(!node1) 
				node1 = pHead2;
			else if(!node2)
				node2 = pHead1;
		}
		return node1;
    }
};
