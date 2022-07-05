// https://www.nowcoder.com/practice/02bf49ea45cd486daa031614f9bd6fc3?tpId=295&tqId=1073463&ru=%2Fpractice%2F3fed228444e740c8be66232ce8b87c2f&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

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
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
		ListNode l1 = ListNode(-1), l2(-2), *odd = &l1, *even = &l2;
		bool flag = true;
		while (head) {
			if(flag) {
				odd->next = head;
				odd = odd->next;
			} else {
				even->next = head;
				even = even->next;
			}
			head = head->next;
			flag = !flag;
		}
		odd->next = l2.next;
		even->next = nullptr;
		return l1.next;
    }
};