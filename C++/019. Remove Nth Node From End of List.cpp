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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow(head), *fast(head);
        while(n--) fast = fast->next;
        if(!fast) return head->next;
        while(fast->next) slow = slow->next, fast = fast->next;
        slow->next = slow->next->next;
        return head;
    }
};
