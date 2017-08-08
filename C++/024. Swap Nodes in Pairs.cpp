/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode res(0);
		ListNode *pre = &res, *one = head, *two = head->next;
		while (one && two) {
			one->next = two->next;
			two->next = one;
			pre->next = two;
			pre = one;
			one = one->next;
			if (one) two = one->next;
		}
		return res.next;
	}
};