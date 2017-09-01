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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* res = pre;
        ListNode* slow(head), *fast(head), *next;
        while(fast){
            int i = k - 1;
            while(fast && i--) fast = fast->next;
            if(fast){
                next = fast->next;
                reverse(pre, slow, fast, next);
                pre = slow;
                slow = next;
                fast = next;
            }
        }
        return res->next;
    }
    
    void reverse(ListNode* left, ListNode* start, ListNode* end, ListNode* right){
        ListNode* pre(left), *cur(start), *next;
        ListNode* tmp = start;
        while(cur != right){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        left->next = pre;
        tmp->next = right;
    }
};
