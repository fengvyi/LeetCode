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
    ListNode* plusOne(ListNode* head) {
        ListNode* p = reverse(head);
        ListNode* tmp = p;
        while(p->val + 1 == 10){
            p->val = 0;
            if(!p->next) p->next = new ListNode(0);
            p = p->next;
        }
        p->val += 1;
        return reverse(tmp);
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* pre = NULL, *cur = head, *next;
        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
