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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(0);
        ListNode right(0);
        ListNode* l = &left;
        ListNode* r = &right;
        ListNode* cur = head;
        while(cur){
            if(cur->val < x){
                l->next = cur;
                l = l->next;
            }
            else{
                r->next = cur;
                r = r->next;
            }
            cur = cur->next;
        }
        r->next = NULL;
        l->next = right.next;
        return left.next;
    }
};
